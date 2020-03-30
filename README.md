/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:41
*     Game: Forward Assault
*     Device: IOS
*/



# How To Use
1. Add All the file to the folder where the "Tweak.xm" is in
2. Add "#import "Telekill.h" to the Tweak.xm
3. Add The "DoTelekill(player)" into the player Update hook

# Example:

#import "Macros.h"
#import "Telekill.h"

void (*_Player_Update)(void *player);
void Player_Update(void *player){

  DoTelekill(player);

  _Player_Update(player);
}



void setup() {
Hook(0x1018A16C8 /*Player.Update() Offset*/, Player_Update, _Player_Update);
}
