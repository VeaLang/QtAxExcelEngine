
/*!
* @copyright  2004-2016  Apache License, Version 2.0 FULLSAIL
* @filename   QtAxExcelEngine.h
* @author     yaoboyuan 254200341@qq.com ԭ��    Sailzeng <sailerzeng@gmail.com> ��д
* @version
* @date       2016��6��10��
* @brief      ����һ��ʹ�� Qt's ActiveX(OLE)��QAxObject ��дEXCEL�ķ�װ�࣬���ڲ�����ʹ��Qt
*             �Ĵ������EXCEL����Ȼ��ʵ��OLE,�㵱Ȼ�����Ȱ�װEXCEL��
*             
*             ����һ������Qt��дexcel��װ���࣬ͬʱ�����ڰ�excel�е�����
*             ��ʾ�������ϣ����߰ѽ����ϵ�����д��excel�У�ͬGUI���н�������ϵ���£�
*             Qt tableWidget <--> ExcelEngine <--> xls file.
* @details
*
*
*
* @note       ExcelEngine��ֻ�����/д���ݣ���������������м��
*
* @history
* @author     yaoboyuan 254200341@qq.com
* @date       2012-4-12
* @note       ԭ��
* @author     Sailzeng ��д <sailerzeng@gmail.com>
* @data       2016-6-7 �����ǰϦ
* @note       ��ԭ�еĴ�������һЩ�Ķ������ӷ���Qt�ı����ʽ�ȡ�
*             ������һЩ���ú��������ӷ���ʵ��
*
*/


#ifndef QT_ACTIVEX_EXCELENGINE_H
#define QT_ACTIVEX_EXCELENGINE_H


// ��WINDOWS�º�POSIX��׼���ݵĺ꣬VS2003���°汾��Σ���û�в��ԣ�2003�Ժ�Windows���ںܶ������ʹ��"_"ǰ׺��
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE 1
#endif
#ifndef _CRT_NONSTDC_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS  1
#endif
#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#endif

// ���ڸ���VC++���Ҳ�ǿ��ʹ��_s���͵�API��_CRT_SECURE_NO_DEPRECATE��_CRT_SECURE_NO_WARNINGS���ϰ汾
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS   1
#endif
#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE  1
#endif

#include <windows.h>

#pragma warning ( push )
#pragma warning ( disable : 4127)

#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <ActiveQt/QAxBase>
#include <ActiveQt/QAxObject>

#include <QtCore/QDebug>
#include <QtGui/QKeyEvent>
#include <QtCore/QVariant>
#include <QtCore/QDir>

#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidgetItem>

#pragma warning ( pop )

/*!
* @brief
*
* note       �������Ҵ���ȫ������Qt�Ĵ�����
*/
class QtAxExcelEngine : protected QObject
{
public:

    //���캯������������
    QtAxExcelEngine();
    ~QtAxExcelEngine();

public:


    /*!
    * @brief      ��ʼ��EXCEL OLE���󣬴�EXCEL ���̣�
    * @return     bool  �����Ƿ�ɹ���
    * @param      visible �Ƿ���EXCEL�ɼ�
    */
    bool initialize(bool visible);

    //!�ͷ��˳����ر�EXCEL����
    void finalize();

    //��һ��XLS�ļ�
    bool open(const QString &xls_file, int  sheet_index = 1);

    /*!
    * @brief      ����һ��sheet��ͬʱ�����������
    * @return     void
    * @param      sheet_name sheet�ı���
    */
    void insertSheet(const QString &sheet_name);

    //����xls����
    void save();

    //�ر�xls����
    void close();

    //�õ�sheet������
    int sheetsCount();

    //�õ�ĳ��sheet������
    bool sheetName(int sheet_index, QString &sheet_name);

    /*!
    * @brief      ������������sheet��
    * @return     bool �����Ƿ�ɹ�����
    * @param      sheet_index sheet��������1��ʼ
	* @param      pre_load �Ƿ����Ԥ���أ�Ԥ���ػ��ȡ����EXCEL��sheet�����ӿ����Ķ�ȡ����
    */
    bool loadSheet(int sheet_index,
				   bool pre_load = false);

    /*!
    * @brief      ����sheet�����������sheet��
    * @return     bool �����Ƿ�ɹ�����
    * @param      sheet_name Ҫ���ص�sheet ������
	* @param      pre_load �Ƿ����Ԥ���أ�Ԥ���ػ��ȡ����EXCEL��sheet�����ӿ����Ķ�ȡ����
    */
    bool loadSheet(const QString &sheet_name,
				   bool pre_load = false);


    /*!
    * @brief      ����Ƿ���������ֵ�sheet
    * @return     bool �з���true�����򷵻�false
    * @param      sheet_name
    */
    bool hasSheet(const QString &sheet_name);

    //�������ݵ�xls
    bool writeTableWidget(QTableWidget *table_widget);

    //��xls��ȡ���ݵ�ui
    bool readTableWidget(QTableWidget *table_widget);

    /*!
    * @brief      ��ȡָ����Ԫ����
    * @return     QVariant  ��Ԫ���Ӧ������
    * @param      row  ��Ԫ����к�,ע���кţ��кŶ��Ǵ�1��ʼ
    * @param      column ��Ԫ����к�
    * @note
    */
    QVariant getCell(int row, int column);

    //�޸�ָ����Ԫ����
    bool  setCell(int row, int column, const QVariant &data);

    //!�򿪵�xls�ļ�����
    QString openFilename() const;

    //!����
    int  rowCount()const;
    //!����
    int  columnCount()const;


    bool is_open();
    bool is_valid();

protected:

    void clear();

    //!���أ��ڲ��������Ժ���Կ�������һ��Ԥ���أ��ӿ��ȡ�ٶȡ�
    void loadSheet_internal(bool pre_load);

public:

    /*!
    * @brief      ȡ���е����ƣ�����27->AA
    * @return     QString
    * @param      column_no
    */
    static QString columnName(int column_no);

private:

    //!ָ������excelӦ�ó���
    QAxObject *excel_instance_ = NULL;

    //!ָ��������,excel�кܶ๤����������Լ�����EXCEL��򿪺ܶ���ļ�
    QAxObject *work_books_ = NULL;

    //!ָ��sXlsFile��Ӧ�Ĺ�����
    QAxObject *active_book_ = NULL;

    //!
    QAxObject *work_sheets_ = NULL;

    //ָ�������е�ĳ��sheet����
    QAxObject *active_sheet_ = NULL;

    //!xls�ļ�·��
    QString xls_file_;

    //!��ǰ�򿪵ĵڼ���sheet
    int curr_sheet_ = 1;
    //!excel�Ƿ�ɼ�
    bool is_visible_ = false;
    //����
    int row_count_ = 0;
    //!����
    int column_count_ = 0;

    //!��ʼ�����ݵ����±�ֵ
    int start_row_ = 0;
    //!��ʼ�����ݵ����±�ֵ
    int start_column_ = 0;

    //!�Ƿ��Ѵ�
    bool is_open_ = false;
    //!�Ƿ���Ч
    bool is_valid_ = false;
    //!�Ƿ���һ���½�xls�ļ����������ִ򿪵�excel���Ѵ����ļ������б����½���
    bool is_a_newfile_ = false;
    //!��ֹ�ظ�����
    bool is_save_already_ = false;

	//Ԥ���صı�������
	QVariantList pre_load_data_;

};

#endif // QT_EXCELENGINE_H