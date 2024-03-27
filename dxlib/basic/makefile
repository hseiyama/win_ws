# 生成する実行ファイル名
TARGET = basic_sam12

# コンパイル対象とするCファイル
SRCS = $(TARGET).cpp
#SRCS = $(TARGET).c

# コンパイル用コマンド
CC = g++
#CC = gcc

# -Wall:警告をすべて出力、-g:デバッグ情報出力
#CFLAGS = -Wall -g
CFLAGS =

build:
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS) \
	-IC:\mingw64\include\DxLib \
	-LC:\mingw64\lib\DxLib \
	-DDX_GCC_COMPILE \
	-lDxLib \
	-lDxUseCLib \
	-lDxDrawFunc \
	-ljpeg \
	-lpng \
	-lzlib \
	-ltiff \
	-ltheora_static \
	-lvorbis_static \
	-lvorbisfile_static \
	-logg_static \
	-lbulletdynamics \
	-lbulletcollision \
	-lbulletmath \
	-lopusfile \
	-lopus \
	-lsilk_common \
	-lcelt

run:
	$(TARGET).exe

clean:
	del $(TARGET).exe
