## Пересечение отрезков

### Задание

Есть класс трёхмерного вектора:
```
class Vector3D
{
double X;
double Y;
double Z;
...
}
```
и трёхмерного отрезка, заданного двумя Vector3D:
```
class Segment3D
{
Vector3D start;
Vector3D end;
...
}
```
Требуется написать функцию Intersect, которая будет находить точку Vector3D пересечения двух
заданных на вход Segment3D. В классы Vector3D и Segment3D можно добавлять любые методы.

### Реализация

Функция Intersect находится в файле core/Segment3D.cc.
Запустить тесты можно командами:
```angular2html
make build
make tests
```
Посмотреть покрытие:
```angular2html
make gcov_report
```

Возвращаемое значение: 
- если отрезки пересекаются - точка пересечения Vector3D
- если отрезки не пересекаются - точка Vector3D с координатами (NAN, NAN, NAN) и исключение, с соответствующим описанием