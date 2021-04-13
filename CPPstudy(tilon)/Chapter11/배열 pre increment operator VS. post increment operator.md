## Pre-increment operator

```C++
#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0 };
	int i = 0;
	arr[++i] = 3;
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << endl;
	}
	return 0;
} 
```
![image](https://user-images.githubusercontent.com/80379900/114527407-ecf39500-9c82-11eb-89be-ee06909dcae7.png)
**출력값:**![image](https://user-images.githubusercontent.com/80379900/114527540-12809e80-9c83-11eb-868f-0befe4b9ed9e.png)


## Post-increment operator
```C++
#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0 };
	int i = 0;
	arr[i++] = 3;
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << endl;
	}
	return 0;
} 
```
![image](https://user-images.githubusercontent.com/80379900/114527710-3f34b600-9c83-11eb-9902-bb63d3a0336b.png)
**출력값:**![image](https://user-images.githubusercontent.com/80379900/114527800-583d6700-9c83-11eb-8597-1b0223e4830f.png)
