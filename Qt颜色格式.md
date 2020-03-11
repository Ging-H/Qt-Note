# Qt颜色格式

```c++
/* 预定义的颜色枚举 */
enum GlobalColor {
  color0,
  color1,
  black,    // 黑色
  white,    // 白色
  darkGray,  // 暗灰
  gray,     // 灰色
  lightGray,	// 亮灰
  red,     	// 红色
  green,			// 绿色
  blue,				// 蓝色
  cyan,				
  magenta,
  yellow,  		// 黄色
  darkRed,   // 暗红
  darkGreen, 	// 暗绿
  darkBlue,		// 暗蓝
  darkCyan,
  darkMagenta,
  darkYellow, // 暗黄
  transparent
};
Qt::darkGreen;// 使用方法
```



```c++
/* 十六进制 */
QColor("#FF7258") // 
```



```c++
/* rgb格式 */
QColor(255, 128, 128, 255)// QColor(r,g,b,a) a是透明度，255为不透明
```

``` c++
/* 样式表颜色格式 */
rgb(50, 50, 50, 255);// rgb(r,g,b,a)a是透明度，255为不透明
color:red;
color:#ff6600;
```

