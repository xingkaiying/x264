#include "ZExpOutput.h"

#ifdef ZTS_OUTPUT
extern "C" zExpResOutput * MyOutput;
#endif 

extern "C" {
	zExpResOutput::zExpResOutput()
	{
		num_views = 0;
		ave_psnr = 0;
	}
	void zExpResOutput::SetSequenceParas(std::string input_sequence, int qp, double f)
	{
		int k;
		std::string z_FileList[8] = {
			// 8 testing set
			"balloons1_texture",
			"Dancer_1_1920x1088_texture",
			"GT_Fly_c_1_1920x1088_texture",
			"Kendo_1024x768_30_01_texture",
			"PoznanHall2_1920x1088_25_05_texture",
			"Newspaper_1024x768_30_04_texture",
			"Shark_1920x1088_30_01_texture",
			"PoznanStreet_1920x1088_cam03_texture.yuv",

		};
		for (k = 0; k < 8; k++)
		{
			if (input_sequence.find(z_FileList[k]) != input_sequence.npos)
				break;
		}
		seq_no = k;
		init_qp = qp;
		cmp_fct = f;
	}

	void zExpResOutput::SetLayerPSNR(double psnr)
	{
		ave_psnr += psnr;
		num_views++;
	}

	void zExpResOutput::SetTotBitrate(double br)
	{
		tot_bitrate = br;
	}
	void zExpResOutput::OutputAll(std::string output_file, double tot_time, double tot_time_depth,
		double dResult_TEXTURE_TOTAL, double dResult_INTRA, double dResult_INTRA_DEPTH, double dResult_INTRA_TEXTURE,
		double dResult_DMM1_TOTAL, double dResult_DMM4_TOTAL, double COARSE_Select_TOTAL_TIME, double REFINE_SELECT_TOTAL_TIME,
		int DMM1_NUM, int DMM4_NUM, int num_4, int num_8, int num_16, int num_32, double Totalcost_view0_ref, double Totalcost_view0_cur, double Totalcost_view1_ref, double Totalcost_view1_cur)
	{
		ave_psnr /= num_views;
		std::ofstream res(output_file, std::ios::out | std::ios::app);
		res << seq_no << "\t" << init_qp << "\t" << cmp_fct << "\t" << Totalcost_view0_ref << "\t" << Totalcost_view0_cur << "\t" << Totalcost_view1_ref << "\t" << Totalcost_view1_cur <<

			/*
			<< DMM1_NUM << "\t" << DMM4_NUM << "\t" << num_4 << "\t"
			<< num_8 << "\t" << num_16 << "\t" <<num_32<< "\t" << dResult_DMM1_TOTAL << "\t" << dResult_DMM4_TOTAL << "\t" << dResult_INTRA_DEPTH <<
			<< tot_time << "\t" << tot_time_depth << "\t" <<
			dResult_TEXTURE_TOTAL << "\t" << dResult_INTRA << "\t" << dResult_INTRA_DEPTH << "\t" << dResult_INTRA_TEXTURE
			<< "\t" << dResult_DMM1_TOTAL << "\t" << COARSE_Select_TOTAL_TIME << "\t" << REFINE_SELECT_TOTAL_TIME  << "\t" <<
			//ave_psnr << "\t" << tot_bitrate <<
			*/
			std::endl;
		res.close();
	}
}