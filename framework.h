// header.h: ��׼ϵͳ�����ļ��İ����ļ���
// ���ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����
// Windows ͷ�ļ�
#include <windows.h>
// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

#include<iostream>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define PAINT_REFRESH WM_USER+1
//KEY_DOWN(1)//:LEFT
//KEY_DOWN(2)//:RIGHT
//KEY_DOWN(4)//���ְ���

