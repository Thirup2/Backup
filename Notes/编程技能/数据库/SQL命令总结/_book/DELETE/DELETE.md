- 使用DELETE的方式
    - 从表中删除特定的行
    - 从表中删除所有行
- 注意点
    - 不要省略WHERE子句, 否则会删除所有行
    - DELETE删除表的内容而不是表本身
    - 当要删除表中所有内容时, 可使用TRUNCATE TABLE语句, 可以更快地删除
- 使用DELETE
    ```sql
    DELETE FROM Customers
    WHERE cust_id = 1000000006;
    ```
- UPDATE与DELETE的原则
    - 除非确实打算更新和删除每一行，否则绝对不要使用不带WHERE子句的UPDATE和DELETE语句
    - 保证每个表都有主键，尽可能像WHERE子句那样使用它
    - 在UPDATE或DELETE语句使用WHERE子句前，应该先用SELECT进行测试，保证它过滤的是正确的记录，以防编写的WHERE子句不正确。
    - 使用强制实施引用完整性的数据库，这样DBMS将不允许删除其数据与其他表相关联的行
    - 有的DBMS允许数据库管理员施加约束，防止执行不带WHERE子句的UPDATE或DELETE语句。如果所采用的的DBMS支持这个特性，应该使用它。