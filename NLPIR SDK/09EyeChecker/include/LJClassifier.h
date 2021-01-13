/****************************************************************************
 *
 * NLPIR Rule-Based Classifier System Copyright (c) 2000-2014
 *     Dr. Kevin Zhang (Hua-Ping Zhang)
 *     All rights reserved.
 *
 * This file is the confidential and proprietary property of 
 * Kevin Zhang and the possession or use of this file requires 
 * a written license from the author.
 * Filename: 
 * Abstract:
 *          LJCLassifier.h: definition of the NLPIR lexical analysis system API
 * Author:   Kevin Zhang 
 *          Email: pipy_zhang@msn.com kevinzhang@bit.edu.cn
 *			Weibo: http://weibo.com/drkevinzhang
 *			Homepage: http://ictclas.nlpir.org
 * Date:     2013-12-19
 *
 * Notes:
 *                
 ****************************************************************************/
#ifndef _H_CLASSIFIER_DLL
#define _H_CLASSIFIER_DLL

#include <string>
using namespace std;
#ifndef OS_LINUX
#pragma warning(disable:4786)
#endif

#ifdef OS_LINUX
#define CLASSIFIER_API  extern "C"
#else
#ifdef LJCLASSIFIER_EXPORTS
#define CLASSIFIER_API extern "C" __declspec(dllexport)
#else
#define CLASSIFIER_API extern "C"  __declspec(dllimport)
#endif
#endif

typedef struct _stDoc 
{
	string sTitle;
	string sContent;
	string sAuthor;
	string sBoard;
	string sDatatype;
}stDoc;


#define GBK_CODE 0//Ĭ��֧��GBK����
#define UTF8_CODE GBK_CODE+1//UTF8����
#define BIG5_CODE GBK_CODE+2//BIG5����
#define GBK_FANTI_CODE GBK_CODE+3//GBK���룬�������������
#define UTF8_FANTI_CODE GBK_CODE+4//UTF8����

/*********************************************************************
*
*  Func Name  : classifier_init
*
*  Description: Init classifier
*               The function must be invoked before any operation listed as following
*
*  Parameters : const char *conf: ��������Ӧ�ķ���XML�����ļ�
*			const char * sInitDirPath=NULL
*				  Path where Data directory stored.
*				 the default value is NULL, it indicates the initial directory is current working directory path
*				 int encode: encoding code;
*				 sLicenseCode: license code for unlimited usage. common user ignore it
*  Returns    : success or fail
*         ������Ϣ��¼��Ӳ�̵�./ljclassifier.log��./DataFile/ljclassifier.log��
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API bool classifier_init(const char *conf="rulelist.xml",const char *sInitDirPath="", int encode = GBK_CODE,const char *sLicenseCode=NULL);

/*********************************************************************
*
*  Func Name  : classifier_exec1
*
*  Description: 
*			���ܣ�����������½ṹ���з���
*  Parameters   ��d:���½ṹָ��
*       iType=0:  �������������֮����\t����  ���ݸ�ʽ��������Ҫ��	����	���ϡ�
*       iType=1:  ������������Ŷȣ�����֮����\t������������Ȩ���á� ������   ���ݸ�ʽ��������Ҫ�� 1.00	���� 0.95	���� 0.82��
*       iType Ĭ��ֵΪ0
*
*  Returns    : �������  ����֮����\t�����������������ŶȴӸߵ�������
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API const char* classifier_exec1(stDoc& d, int iType=0);

/*********************************************************************
*
*  Func Name  : classifier_exec
*
*  Description:
*			���ܣ�����������±��������Ľ��з���
*  Parameters   ��
*		 sTitle:���±���
*	   sContent: ��������
*       iType=0:  �������������֮����\t����  ���ݸ�ʽ��������Ҫ��	����	���ϡ�
*       iType=1:  ������������Ŷȣ�����֮����\t������������Ȩ���á� ������   ���ݸ�ʽ��������Ҫ�� 1.00	���� 0.95	���� 0.82��
*       iType Ĭ��ֵΪ0
*
*  Returns    : �������  ����֮����\t�����������������ŶȴӸߵ�������
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API const char* classifier_exec(const char* sTitle,const char*sContent, int iType);
/*********************************************************************
*
*  Func Name  : classifier_execFile
*
*  Description:
*			���ܣ���������ı��ļ����з���
*  Parameters   ��
*		 sTitle:���±���
*	   sContent: ��������
*       iType=0:  �������������֮����\t����  ���ݸ�ʽ��������Ҫ��	����	���ϡ�
*       iType=1:  ������������Ŷȣ�����֮����\t������������Ȩ���á� ������   ���ݸ�ʽ��������Ҫ�� 1.00	���� 0.95	���� 0.82��
*       iType Ĭ��ֵΪ0
*
*  Returns    : �������  ����֮����\t�����������������ŶȴӸߵ�������
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API const char* classifier_execFile(const char* sFilename, int iType);

/*********************************************************************
*
*  Func Name  : classifier_detail
*
*  Description:
*			���ڵ�ǰ�ĵ�������������ȡ�ý����ϸ
*  Parameters   ��classname:�������
*
*  Returns    : �����ϸ ����:
*		   RULE3:
*		   SUBRULE1: ��Ļ 1	
*		   SUBRULE2: ���� 1	���� 3	��Ʊ 8	
*		   SUBRULE3: ��ժ 2
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API const char* classifier_detail(const char *classname);

/*********************************************************************
*
*  Func Name  : classifier_exit
*
*  Description:
*			�˳����ͷ���Դ
*  Parameters   ����
*
*  Returns    : ��
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API void classifier_exit();

/*********************************************************************
*
*  Func Name  : classifier_setsimthresh
*
*  Description: �������ƶ���ֵ
*			
*  Parameters   ��float fSim
*
*  Returns    : ��
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API void classifier_setsimthresh(float fSim);

/*********************************************************************
*
*  Func Name  : classifier_GetLastErrorMsg
*
*  Description: ��ȡʧ�ܵ���Ϣ
*
*  Parameters   ����
*
*  Returns    : ���صĴ�����Ϣ
*
*  Author     : Kevin Zhang
*  History    :
*              1.create 2013-6-8
*********************************************************************/
CLASSIFIER_API const char* classifier_GetLastErrorMsg();

#endif //_H_CLASSIFIER_DLL

