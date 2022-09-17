#pragma once

const int WINDOW_SIZE_X = 960;
const int WINDOW_SIZE_Y = 480;
const int MAP_SIZE_X = 6720;
const int BLOCK_HIT_RANGE = 10;
const int BLOCK_UP_LIMIT = 60; 
const int BLOCK_UP_AMOUNT = 3; 
const int COINPARTICLE_UP_LIMIT = 120; 
const int COINPARTICLE_UP_AMOUNT = 500; 

const int MarioColliderSize_S_WIDTH = 18; 
const int MarioColliderSize_S_HEIGHT = 32;

const int MarioColliderSize_B_WIDTH = 30;
const int MarioColliderSize_B_HEIGHT = 62;

const int TILE_SIZE = 32;//xy 동일

static bool testMode = false;//콜라이더 드로우 등등

#define KEYBOARD KeyBoard::Get()
#define TIME Time::Get()
#define RENDERER Renderer::Get()
#define RENDERER2 Renderer2::Get()
#define GOM GameObjectManager::Get()

typedef struct
{
	char R;
	char G;
	char B;
}RGB;
/* 사용 예시
RGB color;
color.R = 255;
color.G = 255;
color.B = 255;
*/

// 블록 리소스 디파인
// 이미지 파일 Define
#define BRICKBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/Brick.bmp"
#define ERASERBMP "./Resource/Image/Sprite/Tile/BackGround/BGcolor.bmp"
#define NONBREAKBLOCKBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/NonBreakableBlock.bmp"
#define GROUNDBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/Ground.bmp"
#define UPIPELUBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/UPipeLU.bmp"
#define UPIPERUBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/UPipeRU.bmp"
#define UPIPELDBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/UPipeLD.bmp"
#define UPIPERDBMP "./Resource/Image/Sprite/Tile/BlocksAndItem/UPipeRD.bmp"

#define GAMEOVERBGBMP "./Resource/Image/GameOverBackGround32.bmp"
#define GAMEOVERBMP "./Resource/Image/Gameover.bmp"
#define CLEARBMP "./Resource/Image/Gameclear.bmp"

#define COIN01_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/Coin0.bmp"
#define COIN02_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinGet0.bmp"
#define COIN03_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinGet1.bmp"
#define COIN04_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinGet2.bmp"

#define COINBLOCK01_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinBlock0.bmp"
#define COINBLOCK02_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinBlock1.bmp"
#define COINBLOCK03_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinBlock2.bmp"
#define COINBLOCK_EMPTY_BMP "./Resource/Image/Sprite/Tile/BlocksAndItem/CoinBlockAfterHit.bmp"

#include "resource.h"
#pragma comment(lib, "Msimg32.lib")


#include <windows.h>
#include <assert.h>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include <map>
#include <set>

using namespace std;

#include "DebugPrint/DebugUtils.h"

#include <fmod.hpp>

#include "GameManager/SoundManager.h"


#include "System/Time.h"
#include "System/KeyBoard.h"
#include "System/Transform.h"

#include "Component/0_Component.h"

#include "GameObject/0_MonoBehavior.h"



#include "Component/Bitmap.h"
#include "GameManager/UIManager.h"
#include "System/Renderer.h"
#include "System/Renderer2.h"

#include "Component/Collider.h"
#include "Component/RigidBody.h"
#include "Component/Animation.h"
#include "Component/Animator.h"
#include "Component/Tile.h"
#include "Component/Particle.h"
#include "Component/CoinParticle.h"
#include "Component/Animation.h"
#include "Component/Animator.h"

#include "GameObject/0_GameObject.h"
#include "GameObject/0_GameObjectManager.h"
#include "GameObject/Camera.h"

#include "GameManager/MonsterManager.h"


#include "GameObject/Monster/Monster.h"
#include "GameObject/Monster/Tutle.h"
#include "GameObject/Mario/Mario.h"

#include "GameObject/Item/Item.h"
#include "GameManager/ItemManager.h"
#include "GameObject/Block/BreakableBlock.h"
#include "GameObject/Block/UnbreakableBlock.h"
#include "GameObject/Block/CoinBlock.h"
#include "GameObject/Block/FakeCoinBlock.h"
#include "GameObject/Block/MushroomBlock.h"

#include "GameManager/ParticleManager.h"

#include "Scene/0_Scene.h"
#include "Program.h"
#include "Scene/IntroScene.h"
#include "Scene/TestScene.h"
#include "Scene/GameoverScene.h"
#include "Scene/ClearScene.h"

#include "GameManager/GameManager.h"

