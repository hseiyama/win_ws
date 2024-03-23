# 生成する実行ファイル名
TARGET = sample01

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
	-lgdi32

run:
	$(TARGET).exe

clean:
	del $(TARGET).exe
