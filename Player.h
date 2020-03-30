/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:43
*     Game: Forward Assault
*     Device: IOS
*/


class Player{
public:
  static int get_Team(void *player);

  static float get_Health(void *player);

  static bool get_isMine(void *player);
  static bool get_isLiving(void *player);
};

int Player::get_Team(void *player){
  return *(int *)((uint64_t)player + 0x210);
}

float Player::get_Health(void *player){
  return *(float *)((uint64_t)player + 0x1EC);
}

bool Player::get_isMine(void *player){
  return *(bool *)((uint64_t)player + 0xCC);
}
bool Player::get_isLiving(void *player){
  return Player::get_Health(player) > 1;
}
