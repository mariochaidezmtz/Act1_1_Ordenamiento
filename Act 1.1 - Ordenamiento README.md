**Complejidad Computacional**

| Función | Complejidad Temporal  | Complejidad Espacial  |
| :---- | :---- | :---- |
| busquedaLineal  | O(n)  | O(1)  |
| busquedaBinaria  | O(log₂ n)  | O(1)  |
| busquedaTrinaria  | O(log₃ n)  | O(1)  |

**Metodología**  
Para calcular los tiempos de cada tamaño utilicé una función que iterara 30 veces cada tamaño del vector. Ésta empieza seleccionando un número aleatorio para que en cada iteración se cree un vector diferente ordenado y con la librería chrono se midan los tiempos de cada búsqueda por separado y buscando exactamente el mismo valor en el mismo vector generado aleatoriamente. Para finalizar, se recopilan los datos en variables de clase chrono y se imprimen en consola en microsegundos.

**Tiempo medido en microsegundos**

| Tamaño de entrada | Búsqueda Lineal | Búsqueda Binaria | Búsqueda Trinaria |
| :---- | :---- | :---- | :---- |
| 10^5 | 304.54 | 0.16 | 0.213333 |
| 10^6 | 2725.41 | 0.233333 | 0.266667 |
| 10^7 | 27060.7 | 0.756667 | 0.993333 |
| 10^8 | 295556 | 1.54333 | 1.72667 |

**Análisis**  
Una computadora es capaz de procesar todos estos algoritmos de búsqueda en menos de un segundo, pero si observamos los tiempos exactos de procesamiento cobran sentido las estimaciones matemáticas. Empezando con la búsqueda lineal, como su nombre lo dice es lineal, por lo que busca uno por uno el elemento en el vector hasta encontrarlo. Entonces, si duplicamos el tamaño del vector tardará el doble de tiempo en encontrar el elemento en el peor de los casos, esto se puede observar en la tabla que al aumentar x10 el tamaño, también aumenta x10 el tiempo promedio, significando así un O(n) de tiempo y al guardar siempre el mismo dato, un O(1) de espacio. Por otro lado, para la búsqueda binaria y trinaria el caso es bastante similar. Estas búsquedas seleccionan puntos medios para ir acercándose a donde se encuentra el valor a buscar. Su comportamiento en el tiempo es una función logarítmica O(log n), por ende al ingresar pocos valores se asemejan a una función lineal pero conforme se ingresen valores más grandes la tasa de cambio del tiempo transcurrido, o sea su derivada, irá disminuyendo, siendo mucho más rápido que O(n). Esto se puede observar fácilmente viendo las funciones gráficamente. Igualmente, estas búsquedas siempre guardan la misma cantidad de datos así que su complejidad espacial es O(1). Pero, aunque ambas búsquedas tengan comportamiento similar, la búsqueda binaria tarda un poco menos. La búsqueda trinaria hace 3 divisiones en el vector en vez de 2 y así se va aproximando mejor hacia donde está el valor objetivo, teniendo que hacer menos iteraciones. El problema es que para cada iteración debe comprobar ambos puntos y aparte realizar las operaciones aritméticas para los siguientes puntos. La búsqueda binaria utiliza más iteraciones pero tiene que hacer menos trabajo en cada una que al acumularse suma menos tiempo que la búsqueda trinaria. 