## CSS 网格布局

> `display: grid;`

亦分容器（Container）和子项（Items）两类属性。

`grid-template-columns`指定子项的列数及每项的大小；`grid-template-rows`指定和行数及每项的大小。单位中，`fr`表示可用空间的占比。

`grid-column-gap`指定列间距；`grid-row-gap`指定行间距。`grid-gap`为两者的速记形式。

一个网格模型中，由若干列线（Colmun Lines）和行线（Row Lines）分割而成。起始点从容器的左上角，用`1`表示，而后递增计数。

![grid-lines](./grid-lines.png)

`grid-column`是子项属性，指定该项的水平跨度；`grid-row`则指定项的垂直跨度。值以`number1 / number2`的形式表示。`number1`表示起始线，`number2`表示终止线。

`justify-self`是子项属性，指定该项内容的水平对齐方式，值有`stretch`（默认值）、`start`、`center`、`end`，类似 Flex Box 中的`justify-content`；`align-self`则指定项的垂直对齐方式，取值与前者相同，类似 Flex Box 中的`align-self`。`justify-items`和`align-items`是容器属性，可以同时对齐所有子项。


可以使用`grid-template-areas`来对容器进行区域划分，不要划分的区域使用`.`忽略。
```
grid-template-areas:
  "header header header"        | header | header  | header  |
  "advert content content"  =>  | advert | content | content |
  "footer footer footer";       | footer | footer  | footer  |
```
上面代码将一个容器按名称分为了 9 块 4 类区域，可以按值类比空间分布。子项只需使用`grid-area`来指定对应的区域就行。
```css
.item1 { grid-area: header; }
```

几个有用的函数：
- `repeat([count], [value])`：重复 `count` 个 `value`；
- `minmax([min], [max])`：设定取值的区间在 `min` 和 `max` 之间。

`auto-fill`是根据子项的大小及数量来分配容器的空间，单行不够容纳子项会换行；`auto-fit`与前者类似，只不过它会在子元素无法撑开容器时，撑满整个容器。
```css
// 单行时有空余空间
repeat(auto-fill, minmax(60px, 1fr));

// 单行时均分整个容器
repeat(auto-fit, minmax(60px, 1fr));
```

我们可以利用媒体查询（`@media`）与`grid-template-areas`相结合的方式来设计响应式布局。如：
```html
<style>
  /* 4 个区域，1 列 4 行 */
  .container {
    display: grid;
    grid-template-columns: 1fr;
    grid-template-rows: 50px auto 1fr auto;
    grid-template-areas:
      "header"
      "advert"
      "content"
      "footer";
  }

  .item1 {
    grid-area: header;
  }
  
  .item2 {
    grid-area: advert;
  }

  .item3 {
    grid-area: content;
  }

  .item4 {
    grid-area: footer;
  }

  @media (min-width: 300px) {
    /* 4 个区域，2 列 3 行，左列全为 advert */
    .container {
      gride-template-columns: auto 1fr;
      gride-template-rows: auto 1fr auto;
      grid-template-areas:
        "advert header"
        "advert content"
        "advert footer"; 
    }
  }

</style>

<div class="container">
  <div class="item1">header</div>
  <div class="item1">advert</div>
  <div class="item1">content</div>
  <div class="item1">footer</div>
</div>
```

网格布局可以相互嵌套。