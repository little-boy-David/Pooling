#pragma once
/*
* ������ȫ�ֶ���
*/

#define LOG(str) \
	cout << __FILE__ << ":" << __LINE__ << " " << \
	__TIMESTAMP__ << " : " << str << endl;