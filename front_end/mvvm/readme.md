## MVVM 模式

`MVVM` 即 Model-View-ViewModel 的简写。

- `Model`：存 js 对象，要显示的数据；
- `View`：负责显示`Model`；
- `ViewModel`：前两者的关联，负责把`Model`同步到`View`，及`View`的更新同步到`Model`，即`双向数据绑定`。

脏检测（Angular）
观察者模式和数据拦截（Vue）