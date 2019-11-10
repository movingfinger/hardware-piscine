/*
 *  Center piece movement to paint 3x3 sq ft based on our machinery setup.
 *  @param pos : Encoder reference while moving side way.
 *  @param posH : Encoder reference while moving down way.
*/

void square(long pos, long posH)
{
  while (1) {
  spray();

  moveLeft(190, 100, pos * 0.8);
  moveLeft(190, 100, pos * 0.35);
  moveLeft(190, 110, pos * 0.35);
  moveLeft(185, 130, pos * 0.6);
  stopSpraying();
//  break;

  moveDown(185, 140, 0.55 * posH);
  
//  break;
  spray();

  moveRight(120, 190, pos * 0.7);
  moveRight(110, 170, pos * 0.6);
  moveRight(140, 170, pos * 0.65);
  
//  break;
  stopSpraying();

  moveDown(100, 180, 0.6 * posH);
  
//  break;
  spray();

  moveLeft(175, 155, pos * 0.5);
  moveLeft(165, 150, pos * 0.7);
  moveLeft(155, 170, pos * 0.67);
  
//  break;
  stopSpraying();

  moveDown(200, 150, 0.9 * posH);
  
//  break;
  spray();
//
  moveRight(150, 170, pos * 0.7);
  moveRight(160, 160, pos * 0.5);
  moveRight(170, 145, pos * 0.4);
  
//  break;
  stopSpraying();

  moveDown(125, 190, 0.75 * posH);
  
//  break;
  spray();

  moveLeft(170, 165, pos * 0.5);
  moveLeft(155, 175, pos * 0.7);
  moveLeft(110, 190, pos * 0.3);
  
//  break;
  stopSpraying();

/*
 *  Reset to origin.
*/
  moveRight(170, 200, 1.645 * pos);
  moveUp(200, 200, 4.5 * posH);
  break;
  }
}
