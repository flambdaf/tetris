#include <stdio.h>

#define game_field_lenght 20
#define game_field_width 10
#define tetramino_size 4

typedef struct {
  unsigned score;
  unsigned level;
  unsigned game_field[game_field_lenght][game_field_width];
  unsigned next_tetramino[tetramino_size][tetramino_size];
} Game_struct;

typedef struct {
  unsigned matrix[tetramino_size][tetramino_size];
  int pos_x;
  int pos_y;
} Tetramino_info;

int main(void) {
  Game_struct gs = {
      0, 0, {{0}}, {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}};

  Tetramino_info ti = {
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, 4, 4};

  while (1) {
    for (int i = 0; i < game_field_lenght; i++) {
      for (int j = 0; j < game_field_width; j++) {
        if (i >= ti.pos_y && i < ti.pos_y + tetramino_size && j >= ti.pos_x &&
            j < ti.pos_x + tetramino_size) {
          ti.matrix[i - ti.pos_y][j - ti.pos_x] == 1 ? printf(" ")
                                                     : printf("*");
          continue;
        }
        gs.game_field[i][j] ? printf(" ") : printf("*");
      }
      printf("\n");
    }
    getchar();
    ti.pos_y++;
  }

  return 0;
}