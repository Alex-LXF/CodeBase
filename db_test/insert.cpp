#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>  // 编译器默认从 /usr/include 目录中查头找文件mysql.h 
// 编译器默认从 / usr/include 目录中


int main()
{
    // 1 创建一个数据库连接句柄(操作遥控器)
    MYSQL* connect_fd = mysql_init(NULL);

    // 2. 和数据库建立连接(和tcp的区分开，这是在应用层建立连接)
    //    连接过程需要制定一些必要的信息
    //   MYSQL *mysql_real_connect()参数如下：
    //    a)链接句柄(MYSQL* mysql)
    //    b)服务器的ip地址(const char *host)
    //    c)用户名(const char* user)
    //    d)密码(const char *password)
    //    e)数据库名(const char *db)
    //    f)服务器的端口号(unsigned int port)
    //    g)unix_sock null(const char *unix_socket)
    //    h)client_flag 0(unsigned long client_flag)
    if(mysql_real_connect(connect_fd, "127.0.0.1", "root"
                           , "1225521", "blog_system", 3306, NULL
                           , 0) == NULL)
    {
        printf("连接失败！%s\n", mysql_error(connect_fd));
        return 1;
    }
    printf("连接成功! \n");

    // 3. 设置编码方式
    mysql_set_character_set(connect_fd, "utf8");

    // 4.拼接SQL语句
   char sql[1024 * 4] = {0};
   char title[] = "咏鹅";
   char content[] = "鹅鹅鹅,曲项向天歌";
   int tag_id = 1;
   char data[] = "2019/07/25";
   sprintf(sql, "insert into blog_table values(null,'%s', '%s', %d, '%s')"
           ,title, content, tag_id, data);
   printf("sql: %s\n", sql);

   // 5. 让数据库服务器执行SQL
   int ret = mysql_query(connect_fd, sql);
   if(ret < 0){
       printf("执行sql失败！ %s\n", mysql_error(connect_fd));
       mysql_close(connect_fd);
       return 1;
   }
           // 关闭连接
    mysql_close(connect_fd);
    return 0;
}

