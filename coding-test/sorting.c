	int v, t;
	int i, j;

	if (n > 1)	//n이 1보다 클 동안
	{
		v = a[n-1];	//v를 피봇으로 선언
		i = -1;
		j = n - 1;

		while(1)
		{
			while(a[++i] < v);	//피봇보다 작은 키 찾기
			while(a[--j] > v);	//피봇보다 큰 키 찾기

			if (i >= j) break;	//i가 j이상이면 반복문 탈출
			//a[i]와 a[j]값 교환
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		//a[i]와 a[n-1] 교환
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i);	//왼쪽 부분집합을 정렬
		quickSort(a+i+1, n-i-1);	//오른쪽 부분집합을 정렬
	}
