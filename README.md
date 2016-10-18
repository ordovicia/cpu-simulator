Felis Simulator
===============

2016年度CPU実験B班の1stアーキテクチャ[Felis](https://github.com/wafrelka/felis)用シミュレータ。

## ビルド方法
```shell
$ mkdir build; cd $_
$ cmake ..
$ make
```

リンカエラーを起したときは、もう一回`cmake ..`からやり直せば通ることがあります。

## 使いかた
`simulator`は次のように実行します。

```shell
$ ./simulator -ftest.bin -m256
```

`-f`オプションには機械語ファイルを指定します。
`-m`オプションに数値を指定すると、動的命令がその倍数だけ実行されるたびに画面表示が更新されます。
デフォルトでは1です。

画面の上半分にはレジスタの値が表示されます。
下半分には命令列が書かれています。反転しているのが、次に実行する命令です。
最下部にはコマンドが入力できます。
* run|r -- halt命令まで進めます。
* reset -- 初期状態にリセットします。
* (break|b) [int] -- 指定したプログラムカウンタにbreakpointをはります。
* pb -- breakpointを表示します。
* db [int] -- 指定したbreakpointを削除します。
* step|s -- 命令をひとつ実行します。
* prev|p -- ひとつ前の状態に戻ります。
* quit|q -- 終了します。
* help|h -- ヘルプを表示します。
