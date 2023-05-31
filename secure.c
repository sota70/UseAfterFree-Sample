#include <malloc.h>
#include <unistd.h>

/*
 * ユーザーの情報を保管している構造体
 * ユーザーの権限情報を保管している
 */
struct User {
  char permission;
};

void safeFree(void **ptr);
void login(struct User *user);
int main();

void safeFree(void **ptr) {
  free(*ptr);
  *ptr = NULL;
}

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
    printf("This user ptr is not available\n");
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
 * UseAfterFree脆弱性の対策を施しているので
 * この脆弱性を用いた不正ログインは不可能となっている
 */
int main() {
  struct User *user;
  struct User *newUser;
  user = (struct User *)malloc(sizeof(struct User));
  user->permission = 'u';
  // NOTE: use safeFree function to free user pointer and modify user pointer
  //       so that no one can access the free'd pointer
  printf("user ptr(before): %p\n", user);
  safeFree((void *)&user);
  printf("user ptr(after): %p\n", user);
  newUser = (struct User *)malloc(sizeof(struct User));
  newUser->permission = 'u';
  user->permission = 'r';
  login(newUser);
  return 0;
}
