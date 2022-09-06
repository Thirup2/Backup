- 使用UPDATE的方式:
    - 更新表中的特定行
    - 更新表中的所有行
- 注意点
    1. 不要省略WHERE子句, 不然就会更新表中所有的行
    2. 基本的UPDATE语句由三部分组成:
        - 要更新的表
        - 列名和它们的新值
        - 确定要更新哪些行的过滤条件
- 更新单个列
    ```sql
    UPDATE Customers
    SET cust_email = 'kim@thetoystore.com'
    WHERE cust_id = 1000000005;
    ```
- 更新多个列
    ```sql
    UPDATE Customers
    SET cust_contact = 'Sam Roberts', 
        cust_email = 'sam@toyland.com'
    WHERE cust_id = 1000000006;
    ```
    - 提示: 可以在UPDATE语句中使用子查询
- 删除某个列的值 ( 当定义允许NULL值时)
    ```sql
    UPDATE Customers
    SET cust_email = NULL
    WHERE cust_id = 1000000005;
    ```