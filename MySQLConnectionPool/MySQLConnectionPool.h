#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <memory>
#include <functional>
#include "Connection.h"

using namespace std;
/*
* ʵ�����ӳ�ģ��
*/
class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	// �������̺߳��������û����ӣ��黹ʱ�Ż����ӳ�
	shared_ptr<Connection> getConnection();

private:
	//����#1 ���캯��˽�л�
	ConnectionPool(); 

	//�������ļ��м�������
	bool loadConfigFile();

	//�������̺߳��������ж������߳��У���������������,�������ڷ�����ʳ�Ա����
	void produceConnectionTask();

	//�����̺߳�����ɨ�賬��maxIdleTimeʱ��Ŀ������ӣ����ж�������ӻ���
	void scannerConnectionTask();

	string _ip;// mysql ip
	unsigned short _port; //mysql �˿� Ĭ��3306
	string _username;// mysql �û�����
	string _password;// mysql��¼����
	string _dbname; // ���ݿ�����
	int _initSize;// ���ӳصĳ�ʼ������
	int _maxSize;// ���ӳص����������
	int _maxIdleTime; //���ӳ�������ʱ��
	int _connectionTimeout;//���ӳػ�ȡ���ӵĳ�ʱʱ��

	queue<Connection*> _connectionQue; //�洢mysql���ӵĶ��У��������̰߳�ȫ�ģ�
	mutex _queueMutex;//ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt;// ��¼������������connection���ӵ��������������������������������仯���̰߳�ȫ����
	condition_variable cv; //���������������������� �����̺߳������̵߳�ͨ��
};

