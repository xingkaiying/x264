//
//#ifndef __ZTS_EO_H__
//#define __ZTS_EO_H__
//
//#include <iostream>
//#include <fstream>
//#include<iostream>
//#include<stdio.h>
//#define ZTS_OUTPUT 
//
//typedef struct ZExpOutput {
//	int num_views;
//	int seq_no;
//	int init_qp;
//	double cmp_fct;
//	double ave_psnr;
//	double tot_bitrate;
//	double Enc_time;
//}ZExpOutput;
//
//ZExpOutput out;
//void OutputFile();
//
//class zExpResOutput {
//public:
//	zExpResOutput();
//	~zExpResOutput();
//	void SetSequenceParas(std::string input_sequence, int qp, double f);
//	void SetLayerPSNR(double psnr);
//	void SetTotBitrate(double br);
//	void OutputAll(std::string output_file, double tot_time, double tot_time_depth, double dResult_TEXTURE_TOTAL,
//		double dResult_INTRA, double dResult_INTRA_DEPTH, double dResult_INTRA_TEXTURE, double dResult_DMM1_TOTAL, double dResult_DMM4_TOTAL,
//		double COARSE_Select_TOTAL_TIME, double REFINE_SELECT_TOTAL_TIME,
//		int DMM1_NUM, int DMM4_NUM, int num_4, int num_8, int num_16, int num_32, double Totalcost_view0_ref, double Totalcost_view0_cur, double Totalcost_view1_ref, double Totalcost_view1_cur);
//
//private:
//	int num_views;
//	int seq_no;
//	int init_qp;
//	double cmp_fct;
//	double ave_psnr;
//	double tot_bitrate;
//};
//
//#ifdef ZTS_OUTPUT
//extern zExpResOutput* MyOutput;
//#endif 
//
//#endif __ZTS_EO_H__