#include <DxLib.h>
#include <stdio.h>

int handle;//�n���h���p�ϐ���錾

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
    ChangeWindowMode( TRUE );//��S��ʂɃZ�b�g
    SetGraphMode( 640 , 480 , 32 );//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag( FALSE ) ;//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if(DxLib_Init() == 1){return -1;}//�������Ɏ��s���ɃG���[��f�����ďI��

    handle = LoadGraph("sample.png");

    while( ProcessMessage()==0 )
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen( DX_SCREEN_BACK ) ;//�`���𗠉�ʂ�

        DrawGraph(0, 100, handle, 0);//�`��

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}