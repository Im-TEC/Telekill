/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:43
*     Game: Forward Assault
*     Device: IOS
*/


class TPlayer{
public:
  static int get_Team(void *TPlayer);

  static float get_Health(void *TPlayer);

  static bool get_isMine(void *TPlayer);
  static bool get_isLiving(void *TPlayer);
};

int TPlayer::get_Team(void *TPlayer){
  return *(int *)((uint64_t)TPlayer + 0x210);
}

float TPlayer::get_Health(void *TPlayer){
  return *(float *)((uint64_t)TPlayer + 0x1EC);
}

bool TPlayer::get_isMine(void *TPlayer){
  return *(bool *)((uint64_t)TPlayer + 0xCC);
}
bool TPlayer::get_isLiving(void *TPlayer){
  return TPlayer::get_Health(TPlayer) > 1;
}
