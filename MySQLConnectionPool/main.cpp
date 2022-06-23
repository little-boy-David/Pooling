#include <iostream>
#include <thread>
#include "Connection.h"
#include "MySQLConnectionPool.h"


using namespace std;


int main()
{
	/*
	 * ���ݿ����
	*/
	//Connection conn;
	//char sql[1024] = { 0 };
	//sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//conn.update(sql);

	//ѹ�����ԣ�
	// 
	//�ٲ������ӳأ����߳�,��������1000��5000��10000
	clock_t begin = clock();
	for (int i = 0; i < 1000; ++i) {
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "root", "chat");
		conn.update(sql);
	}
	clock_t end = clock();
	cout << end - begin << "ms" << endl;

	//�������ӳص��̣߳���������1000��5000��10000
	//clock_t begin = clock();
	//ConnectionPool *cp = ConnectionPool::getConnectionPool();
	//for (int i = 0; i < 5000; ++i) {
	//	shared_ptr<Connection> sp= cp->getConnection();
	//	char sql[1024] = { 0 };
	//	sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//	sp->update(sql);
	//}
	//clock_t end = clock();
	//cout << end - begin << "ms" << endl;

	//�۲������ӳص�4�߳�
	//�����ڶ��߳���ͬʱ�������ݿ⣬�ǷǷ���,��Ҫ����������������
	//Connection conn;
	//conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//clock_t begin = clock();
	//thread t1([]() {
	//	for (int i = 0; i < 250; ++i) {
	//		Connection conn;
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//		conn.update(sql);
	//	}
	//	});
	//thread t2([]() {
	//	for (int i = 0; i < 250; ++i) {
	//		Connection conn;
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//		conn.update(sql);
	//	}
	//	});
	//thread t3([]() {
	//	for (int i = 0; i < 250; ++i) {
	//		Connection conn;
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//		conn.update(sql);
	//	}
	//	});
	//thread t4([]() {
	//	for (int i = 0; i < 250; ++i) {
	//		Connection conn;
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//		conn.update(sql);
	//	}
	//	});
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();
	//clock_t end = clock();
	//cout << end - begin << "ms" << endl;

	//�������ӳص�4�߳�
	//clock_t begin = clock();
	//thread	t1([]() {
	//	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	//	for (int i = 0; i < 250; ++i) {
	//		shared_ptr<Connection> sp = cp->getConnection();
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		sp->update(sql);
	//	}
	//	});
	//thread	t2([]() {
	//	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	//	for (int i = 0; i < 250; ++i) {
	//		shared_ptr<Connection> sp = cp->getConnection();
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		sp->update(sql);
	//	}
	//	});
	//thread	t3([]() {
	//	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	//	for (int i = 0; i < 250; ++i) {
	//		shared_ptr<Connection> sp = cp->getConnection();
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		sp->update(sql);
	//	}
	//	});
	//thread	t4([]() {
	//	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	//	for (int i = 0; i < 250; ++i) {
	//		shared_ptr<Connection> sp = cp->getConnection();
	//		char sql[1024] = { 0 };
	//		sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//		sp->update(sql);
	//	}
	//	});
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();
	//clock_t end = clock();
	//cout << end - begin << "ms" << endl;

	return 0;
}