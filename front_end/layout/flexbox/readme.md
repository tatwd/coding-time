## 弹性盒子布局

即 Flex Box 布局。 

有两类属性，分别作用于弹性盒容器（Flex Container）和子项（Flex Items）。

有两根轴：主轴（Main Axis）和交叉轴（Cross Axis）。这两根轴的方向取决于`flex-direction`的取值。当`flex-direction: row`（默认值）时，主轴方向水平，交叉轴方向垂直；当`flex-direction: column`时，主轴方向垂直，交叉轴方向水平；

![flex-direction-terms](./flex-direction-terms.svg)

`flex-wrap`用来控制容器的包含子项的规则。`nowrap`默认值；`wrap`主轴占满则换行；`wrap-reverse`交叉轴占满则换行。

`justify-content`、`align-items`和`flex-wrap`属性的作用效果依赖于这两根轴。

`flex-shrink`作用于子项，控制单个子项的缩放，参照其他子项，数值愈大，缩放程度愈大（如宽度愈小）。