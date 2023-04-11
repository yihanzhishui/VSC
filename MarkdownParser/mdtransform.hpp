#include <iostream>

/**
 * 0: null                          |开始
 * 1: <p>                           |段落
 * 2: <a href=" ">...</a>           |超链接
 * 3: <ul>                          |无序列表
 * 4: <ol>                          |有序列表
 * 5: <li>                          |列表
 * 6: <em>                          |斜体
 * 7: <strong>                      |加粗
 * 8: <hr />                        |水平分割线
 * 9: <br />                        |换行
 * 10: <img alt="" src="" />        |图片
 * 11: <blockquote>                 |引用
 * 12: <h1>                         |h1
 * 13: <h2>                         |h2
 * 14: <h3>                         |h3
 * 15: <h4>                         |h4
 * 16: <h5>                         |h5
 * 17: <h6>                         |h6
 * 18: <pre><code>                  |代码段
 * 19: <code>                       |行内代码
 */

class MarkdownTransform {
  private:
    std::string file_name;

  public:
    // 构造函数
    MarkdownTransform(std::string m_file_name) : file_name(m_file_name){};
    // 获取 Markdown 文件 HTML 格式的目录
    std::string getTableOfContents();
    // 获取 Markdown 转成 HTML 后的内容
    std::string getContents();
};

// 获取 Markdown 文件 HTML 格式的目录
std::string MarkdownTransform::getTableOfContents() {}

// 获取 Markdown 转成 HTML 后的内容
std::string MarkdownTransform::getContents() {}