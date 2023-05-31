#include <malloc.h>
#include <unistd.h>

/*
 * ユーザーの情報を保管している構造体
 * ユーザーの権限情報を保管している
 */
struct User {
  char permission;
};

void login(struct User *user);
int main();

/*
 * ユーザーの情報に応じて、適切な権限でログイン処理を行う関数
 * この関数内では、擬似的にログイン処理を行っているだけで
 * 実際のログイン処理は行っていない
 *
 *
 * param user: ユーザーの情報を保管している構造体
 *             この構造体にはユーザーの権限情報が保管されている
 *
 * return: 無し
 */
void login(struct User *user) {
  if (user == NULL) {
    printf("user pointer is not available\n");
    return;
  }
  if (user->permission == 'u') {
    printf("Log in as an user\n");
    return;
  }
  if (user->permission == 'r') {
    printf("Log in as a root\n");
    return;
  }
  printf("Something went wrong\n");
}

/*
 * Main関数
 * UseAfterFree脆弱性を再現するために、二つのUser構造体を使う
 * まず最初に1つ目のUser(変数名はuser)をメモリ上に確保する
 * そして、確保したメモリーを開放し、次User構造体の領域を確保する時にuserの領域を確保するようにする
 * そうしたら、２つ目のUser構造体(変数名はnewUser)の領域を確保する
 * この状況下で、userのポインターを使いnewUserの構造体にアクセスが可能となる
 *
 * return: exitコードを返す(0の場合成功。1の場合失敗)
 */
int main() {
  struct User *user;
  struct User *newUser;
  user = (struct User *)malloc(sizeof(struct User));
  user->permission = 'u';
  free(user);
  newUser = (struct User *)malloc(sizeof(struct User));
  newUser->permission = 'u';
  user->permission = 'r';
  login(newUser);
  return 0;
}
