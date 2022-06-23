#include <iostream>
#include <thread>
#include "Connection.h"
#include "MySQLConnectionPool.h"


using namespace std;


int main()
{
	/*
	 * 数据库测试
	*/
	//Connection conn;
	//char sql[1024] = { 0 };
	//sprintf(sql, "insert into user(name, age, sex) values ('%s', %d, '%s')", "zhang san", 20, "male");
	//conn.connect("127.0.0.1", 3306, "root", "root", "chat");
	//conn.update(sql);

	//压力测试：
	// 
	//①不用连接池，单线程,更改数据1000、5000、10000
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

	//②用连接池单线程，更改数据1000、5000、10000
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

	//③不用连接池的4线程
	//不能在多线程中同时连接数据库，是非法的,需要先在外面声明连接
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

	//④用连接池的4线程
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