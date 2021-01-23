#include <stdio.h>
#include <math.h>

/*20164385 ��ǻ�Ͱ��а� ������
  20164404 ��ǻ�Ͱ��а� ������ */

int EEA(int a, int b);

int main() {
	int p = 29;
	int q = 31;
	int e = 571;
	int m = 115;   //������

	printf(">>RSA �˰��� <<\n");
	printf("p = %d, q = %d, e = %d�� ���� �����ִ�.\n\n", p, q, e);
	printf("B�� ����Ű�� ����Ű�� �����Ѵ�.\n");
	//n ���ϱ�   n = p * q
	int n = p * q;
	printf("n : %d\n", n);

	//d ���ϱ�   (e * d) mod ��(n) = 1
	int d;
	int pi = (p - 1) * (q - 1);   //��(n) = (p-1) * (q-1)
	printf("pi : %d\n", pi);
	/*for (int i = 2; i < pi; i++) {   //Ȯ�� ��Ŭ���� ȣ���� ������� ���� �ҽ�
	 if ((e * i) % pi == 1)
	 d = i;
	 }*/
	d = EEA(e, pi);   //Ȯ�� ��Ŭ���� ȣ���� ���

	printf("d : %d\n\n", d);

	printf("����Ű = (%d, %d), ����Ű = (%d, %d)\n", n, e, n, d);
	printf("B�� ����Ű�� A���� �ش�.\n\n");
	//��ȣȭ
	//���̺귯�� �Լ� ����ϸ� �ּ� ����� ����
	//long long C = ((long long)pow(m, e) % n);
	//printf("��ȣ�� : %lld\n", C);
	int C = 1;
	for (int i = 0; i < e; i++) {
		C *= m;
		C %= n;
	}
	printf("A�� ��ȣȭ�� ������ : %d\n", m);
	printf("��ȣ�� : %d\n", C);

	//��ȣȭ
	//long long M = ((long long) pow(C, d) % n);
	//printf("��ȣ�� : %lld\n", M);
	int M = 1;
	for (int i = 0; i < d; i++) {
		M *= C;
		M %= n;
	}
	printf("��ȣ���� ���� B�� �ص��Ѵ�.\n\n");
	printf("��ȣ�� : %d", M);
}

int EEA(int a, int b) {
	printf("\n>>Ȯ�� ��Ŭ���� ȣ���� <<\n");
	int tmpa = a, tmpb = b;  //ab �޴°�
	int acnt = 1, acnt1 = 0;   //a�� ������ �����ϴ� ��
	int bcnt = 0, bcnt1 = 1;   //b�� ������ �����ϴ� ��
	int tmp = 0, c = 0, cnt =0;
	while (tmpb) {
		if (cnt)
			printf("(x = %5d,  y = %5d) -> %5d = ", bcnt1, acnt1, tmpa);

		c = tmpa / tmpb;
		tmp = tmpa;
		tmpa = tmpb;
		tmpb = tmp - tmpb * c;
		tmp = acnt;
		acnt = acnt1;
		acnt1 = tmp - acnt1 * c;
		tmp = bcnt;
		bcnt = bcnt1;
		bcnt1 = tmp - bcnt1 * c;
		if (cnt)
			printf("%5d * %5d + %5d\n", c, tmpa, tmpb);
		cnt++;

	}
	printf("\n>>Ȯ�� ��Ŭ���� ȣ���� ���<<\n");
	printf("(x = %5d, y = %5d) -> %5d = %5d * %5d + %5d * %5d\n", bcnt, acnt, tmpa, b, bcnt,bcnt1, acnt);

	return acnt;
}
