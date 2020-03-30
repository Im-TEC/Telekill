/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:59
*     Game: Forward Assault
*     Device: IOS
*/
#import "Player.h"
#import "Vector3.h"

/*Here we get the right offset*/
uint64_t getRightOffset(uint64_t offset){
	return _dyld_get_image_vmaddr_slide(0) + offset;
}


 void *(*Component$$get_transform)(void *component) = (void *(*)(void *))getRightOffset(0x1023721E0);
 void (*Transform$$get_position_Injected)(void *Transform, Vector3 *outPosition) = (void (*)(void *, Vector3 *))getRightOffset(0x10239DA4C);
 void (*Transform$$set_position_Injected)(void *Transform, Vector3 outPosition) = (void (*)(void *, Vector3))getRightOffset(0x10239DAF4);

/*Here we get the position the easier way*/
Vector3 getPosition(void *component){
  /* Varible to get the position*/
  Vector3 out;
  /*get the transform of the object*/
  void *transform = Component$$get_transform(component);
  /* Set the out varible to the position of the object*/
  Transform$$get_position_Injected(transform, &out);
  /* Return the verible out*/
  return out;
}

/*Here we set the position the easier way*/
void setPosition(void *component, Vector3 newPosition){
  /*get the transform of the object*/
  void *transform = Component$$get_transform(component);
  /* set the object position to the new position*/
  Transform$$set_position_Injected(transform, newPosition);
}

void *myTPlayer = NULL;

void DoTelekill(void *TPlayer){
  /* Here we see if the TPlayer is mine */
  if(TPlayer::get_isMine(TPlayer)){
    /* Set myTPlayer varible to the TPlayer sense the TPlayer is mine*/
    myTPlayer = TPlayer;
    /* End. Stopping the process*/
    return;
  }
  /* Here we do all the checks to make sure that the TPlayer is a live and aint on my team and my TPlayer is a thing and a live */
  if(myTPlayer && TPlayer::get_isLiving(TPlayer) && TPlayer::get_isLiving(myTPlayer) && TPlayer::get_Team(myTPlayer) != TPlayer::get_Team(TPlayer)){
    /* Get the position of the enemy TPlayer*/
    Vector3 ePosition = getPosition(TPlayer);
    /* Set the my TPlayer position to the enemy TPlayer position*/
    setPosition(myTPlayer, Vector3(ePosition.x, ePosition.y + 1, ePosition.z + 1));
  }
}
