#include <DxLib.h>
#include <stdio.h>

//�L�[�擾�p�̔z��
char buf[256] = { 0 };
int keyState[256] = { 0 };

//�L�[���͏�Ԃ��X�V����֐�
void KeyUpdate()
{
    GetHitKeyStateAll(buf);
    for (int i = 0; i< 256; i++)
    {
        if (buf[i] == 1) keyState[i]++;
        else keyState[i] = 0;
    }
}

int handle;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
    SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if (DxLib_Init() == 1){ return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

    handle = LoadSoundMem("sample.wav");

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

        KeyUpdate();//�L�[���͏�Ԃ��X�V����i����֐��j

        //keyState�z��ɂ́A�e�L�[�����t���[�������ꑱ���Ă��邩�������Ă���
        DrawFormatString(100, 100, GetColor(255, 255, 255), "Z KEY %d", keyState[KEY_INPUT_Z]);

        if (keyState[KEY_INPUT_Z] == 1){
            PlaySoundMem(handle, DX_PLAYTYPE_BACK);
        }

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
