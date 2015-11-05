/**********************************************************************
* 版权所有 (C)2015, Zhou Zhaoxiong。
*
* 文件名称：TestAlign.c
* 文件标识：无
* 内容摘要：示例对文件内容对齐和填充的处理
* 其它说明：无
* 当前版本：V1.0
* 作   者：Zhou Zhaoxiong
* 完成日期：20150901
*
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 重定义数据类型
typedef signed   int  INT32;
typedef signed   char INT8;

// 函数声明
void WriteFile(INT32 iAlignFlag, INT8 *pszTestStr);

/**********************************************************************
* 功能描述：主函数
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期        版本号            修改人            修改内容
* -------------------------------------------------------------------
* 20150901        V1.0           Zhou Zhaoxiong        创建
***********************************************************************/
INT32 main()
{
    INT32 iAlignFlag   = 0;
    INT8 szTestStr[50] = {0}; 

    printf("请输入对齐方式(1, 2, 3, 4)和测试字符串\n");

    scanf("AlignFlag=%d, TestStr=%s", &iAlignFlag, szTestStr);

    printf("输入信息: 对齐方式%d, 测试字符串%s\n", iAlignFlag, szTestStr);

    WriteFile(iAlignFlag, szTestStr);   // 调用写文件函数

    return 0;                 // main函数执行成功返回0
}


/**********************************************************************
* 功能描述：根据对齐方式写文件
* 输入参数：iAlignFlag-对齐方式
            pszTestStr-测试字符串
* 输出参数：无
* 返 回 值：无
* 其它说明：设基准长度为10个字节, 未达到则补空格或0
* 修改日期      版本号            修改人            修改内容
* -------------------------------------------------------------------
* 20150901      V1.0          Zhou Zhaoxiong       创建
***********************************************************************/
void WriteFile(INT32 iAlignFlag, INT8 *pszTestStr)
{
    FILE *fp             = NULL;
    INT8 szContent[50]   = {0};
    INT8 szFileName[50]  = {0};

    if (pszTestStr == NULL)   // 判断输入参数是否为空
    {
        printf("WriteFile: input parameter(s) is NULL!");
        return;
    }

    if (iAlignFlag == 1)     // 左对齐, 不足的位补空格
    {
        _snprintf(szContent, sizeof(szContent)-1, "%10s", pszTestStr);
    }

    if (iAlignFlag == 2)     // 右对齐, 不足的位补空格
    {
        _snprintf(szContent, sizeof(szContent)-1, "%-10s", pszTestStr);
    }

    if (iAlignFlag == 3)     // 左对齐, 不足的位补0
    {
        _snprintf(szContent, sizeof(szContent)-1, "%-s%0*d", pszTestStr, 10-strlen(pszTestStr), 0);
    }

    if (iAlignFlag == 4)     // 右对齐, 不足的位补0
    {
        _snprintf(szContent, sizeof(szContent)-1, "%0*d%s", 10-strlen(pszTestStr), 0, pszTestStr);
    }

    // 将文件内容写入
    strcpy(szFileName, "D:\\Test\\TestFile.txt"); // 注意: 文件目录是双\, 不要写成"D:\Test\TestFile.txt"
    fp = fopen(szFileName, "w");
    if (fp != NULL)
    {
        fputs(szContent, fp);
        fclose(fp);
        fp = NULL;
        printf("WriteFile: Write %s into file successfully!\n", szContent);
    }
    else
    {
        printf("WriteFile: Write %s into file failed!\n", szContent);
    }
}
