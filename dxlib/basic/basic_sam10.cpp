#include <DxLib.h>
#include <stdio.h>

int mouseX = 0;//�}�E�X���W
int mouseY = 0;//�}�E�X���W

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
    SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if (DxLib_Init() == 1){ return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

    int handle = LoadGraph("sample.png");

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

        GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, mouseX);
        DrawGraph(100, 100, handle, 0);

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
