# bad apple on GBA 
有屏幕的地方就有烂苹果

## 使用说明
1. 源代码在 bad_apple 目录下面。

2. 编译器在 GsLIB 目录下面

3. 编译方法 
   3.1 进入GsLIB  双击 gsgo.bat 
   3.2 会打开一个终端，在这个终端使用doc命令进入 bad_apple 目录下。 ps: CD path
   3.3 进入代码目录后，在终端输入"make"(双引号中的)，程序会自动进行编译，最后可以看到编译结果。当前目录下新生成的main.bin文件就是可以用GBA模拟器运行的程序了。

   3.4 如果编译过程中出现 not find main.c 类似的，可以删除代码目录下的 Makedepend 文件，在进行从试

4. 其他问题

   4.1 本程序只是简单实现，每一帧切换没有考虑使用时钟，所以视频时长和标准的不同步。

   4.2 这份代码是现学现卖的，用了一个下午写的。没有准备音频。

   4.3 arm251（GsLIB中 arm交叉编译器）是 WinXP年代的产物，我运气能在 win7 x64上运行，在win8、win10我不清楚能否运行。


   4.4 视频帧使用的游程编码压缩。这部分以后在详细写。

   4.4.1 粗略介绍下：

   ​	a. 统一放在 bad_apple_buf.c 的全局u16数组中。

   ​	b. GBA屏幕显示的像素是240*160 ，每一帧的格式是 { 该帧有的成员数量n , 黑色数量a1，白色数量a2，...，黑色（白色）数量an  } ,注意的是“黑色（白色）数量” 是实际数量的一半（为了压缩数据体积）。而且程序是行为主。

5. 展示

   ![display](https://raw.githubusercontent.com/ydar95/bad_apple_on_gba/master/readme_resource/display.png)

   ​
