#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_dir(char *dirname);
void print_dirent(struct dirent *de);

/*カレントディレクトリの内容一覧を表示*/
int main(void) {
  scan_dir(".");
  return 0;
}

/*指定ディレクトリをスキャンして表示関数を呼ぶ*/
void scan_dir(char *dirname) {
  /*ディレクトリファイルをオープン*/
  DIR *dirp = opendir(dirname);
  if (dirp == NULL){ /*オープン失敗*/
    perror("opnedir");
    exit(1);
  }
  /*ディレクトリエントリを順次リード*/
  for (;;) {
    struct dirent *de = readdir(dirp);
    if (de == NULL) { /*終わり*/
      break;
    }
    /*ディレクトリエントリを表示*/
    print_dirent(de);
  }
  /*ディレクトリファイルをクローズ*/
  closedir(dirp);
}

/*ディレクトリエントリを表示*/
void print_dirent(struct dirent *de)
{
  if (de->d_type == DT_REG) { /*種別:通常ファイル*/
    int fnlen = strlen(de->d_name);
    /* ファイル名の長さ: 3以上 */
    /* ファイル名の後ろから2文字が ".c" */
    if ((fnlen >= 3) && 
        (strcmp(".c", &de->d_name[fnlen-2]) == 0)) {
      printf("%s\n", de->d_name);
    }
  }
}
