## 弹性盒子布局

> `display: flex;`

即 Flex Box 布局。 

有两类属性，分别作用于弹性盒容器（Flex Container）和子项（Flex Items）。

有两根轴：主轴（Main Axis）和交叉轴（Cross Axis）。这两根轴的方向取决于`flex-direction`的取值。当`flex-direction: row`（默认值）时，主轴方向水平，交叉轴方向垂直；当`flex-direction: column`时，主轴方向垂直，交叉轴方向水平。

![flex-direction-terms](./flex-direction-terms.svg)

`flex-wrap`用来控制容器的包含子项的规则。`nowrap`默认值；`wrap`主轴占满则换行；`wrap-reverse`交叉轴占满则换行。

`flex-shrink`作用于子项，控制子项在容器收缩时的大小，参照其他子项，数值愈大，缩放程度愈大（如宽度愈小）。

`flex-grow`与`flex-shrink`的作用相反，控制子项在容器扩大时的大小。

`flex-basis`指定子项的初始大小，值`auto`表示（主轴的）大小取决于内容。

`flex`是`flex-grow`、`flex-shrink`和`flex-basis`的速记形式，默认`flex: 0 1 auto`。

`order`指定子项在主轴上的顺序，值愈小愈前。值`> 0`。

`align-self`可自定义子项的交叉轴对齐方式，值与`align-items`相同。

> `float`， `clear`和`vertical-align`无法作用于子项。
