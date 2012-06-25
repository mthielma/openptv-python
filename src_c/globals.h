/*  global declarations for ptv  */

#define nmax 20240

	int    	n_img;			       /* no of images */
 	 int		hp_flag;           	       /* flag for highpass */
 	 int		allCam_flag;           	       /* flag for using all cams for points */
	int    	tiff_flag;	               /* flag for tiff header */
	int    	chfield;	               /* flag for field mode */
	int    	nfix;	       		       /* no. of control points */
	int    	num[]; 			       /* no. of particles per image */
	int    	nump[4]; 	       	       /* no. of particles in previous image */
	int    	numc[4]; 	       	       /* no. of particles in current image */
	int    	numn[4]; 	       	       /* no. of particles in next image */
	int    	n_trac[];      		       /* no. of tracks */
 	 int    	match; 			       /* no. of matches */
	int    	match2;		    	       /* no. of matches in 2nd pass */
	int 	match4_g, match3_g, match2_g, match1_g;
 	 int     corp, corc, corn;              /* no. of correspondences in p,c,n */
	int             x_calib[4][1000];
	int             y_calib[4][1000];
	int             z_calib[4][1000];
	int 		ncal_points[4];	
	int             orient_x1[4][1000];
	int             orient_y1[4][1000];
	int             orient_x2[4][1000];
	int             orient_y2[4][1000];
	int 		orient_n[4];	
	char    seq_ch[128], seq_name[4][128];
	
    double seq_slice_step,seq_slicethickness,seq_zdim,seq_dummy;
    int dumbbell_pyptv;
    
    int seq_step_shake;
    
//Denis - globals for tracking function
	double lmax_track,ymax_track,ymin_track;
	double npart,nlinks;
	int intx0_tr[4][10000],inty0_tr[4][10000],intx1_tr[4][10000],inty1_tr[4][10000],intx2_tr[4][10000],inty2_tr[4][10000], pnr1_tr[4][10000],pnr2_tr[4][10000],m1_tr;
	double pnr3_tr[4][10000];
    
// Denis - arrays for rclick mouse processing
    int rclick_intx1[4],rclick_inty1[4],rclick_intx2[4],rclick_inty2[4], rclick_points_x1[4][10000],rclick_points_y1[4][10000],rclick_count[4],rclick_points_intx1,rclick_points_inty1;
// --------------------------------

	int    	nr[4][4];		       /* point numbers for man. ori */
	int    	imx, imy, imgsize;     	       /* image size */
	int    	zoom_x[], zoom_y[], zoom_f[];  /* zoom parameters */
	int    	pp1, pp2, pp3, pp4,pp5;	       /* for man. orientation */
	int    	seq_first, seq_last;	       /* 1. and last img of seq */
	int    	demo_nr;		       /* for demo purposes */
	 int    	examine;       		       /* extra output */
	int    	dump_for_rdb;		       /* # of dumpfiles for rdb */
 	 int     cr_sz;                         /* size of crosses */
 	 int     display;                       /* display flag */
 	 int     m[4];
 	 int     trackallocflag;  /* checkflag if mega, c4, t4 already allocated */

	double 	pix_x, pix_y;		     	/* pixel size */
	double 	pi, ro;				/* pi, ro */
	double 	cn, cnx, cny, csumg, eps0, corrmin;	 /* correspond. par */
	double 	rmsX, rmsY, rmsZ, mean_sigma0;		 /* a priori rms */
	double  X_lay[],   Zmin_lay[],   Zmax_lay[];         /* illu. layer current slice */
  	double  db_scale;           /*dumbbell length, Beat Mai 2010*/ 

	FILE   	*fp1, *fp2, *fp3, *fp4, *fpp;	/* file pointers */

	char  img_name[4][256];	        /* original image names */
	char  img_lp_name[4][256];    	/* lowpass image names */
	char  img_hp_name[4][256];      /* highpass image names */
	char  img_cal[4][128];		/* calibration image names */
	char  img_ori[4][128];		/* image orientation data */
	char  img_ori0[4][128];		/* orientation approx. values */
	char  img_addpar0[4][128];	/* approx. image additional parameters */
	char  img_addpar[4][128];	/* image additional parameters */
	char  fixp_name[128];	/* testfield fixpoints */
	char  seq_name[4][128];      	/* sequence names */
	char  track_dir[128];	       	/* directory with dap track data */
	char  res_name[128];	       	/* result destination */
	char  buf[], val[];		       	/* buffer */
	char  filename[128];

	unsigned char	*img[];			/* image data */
	unsigned char	*zoomimg;		/* zomm image data */

 Exterior         Ex[];	       	/* exterior orientation */ //previous -  Exterior  Ex[];
	Interior       	I[];	        /* interior orientation *///previous -  Exterior  I[];
	Glass       	G[];	        /* glass orientation *///previous -  Exterior  G[];
	ap_52	       	ap[];	       	/* add. parameters *///previous -  Exterior  ap[];
	mm_np	       	mmp;	       	/* 3-media parameters */
	target	       	pix[4][nmax];  	/* target pixel data */
	target	       	pix0[4][12];    	/* pixel data for man_ori points */
	coord_2d       	crd[4][nmax];  	/* (distorted) metric coordinates */
	coord_2d       	geo[4][nmax];  	/* corrected metric coordinates */
	coord_3d       	fix[];	        /* testfield points coordinates */
	n_tupel	       	con[];	      	/* list of correspondences */
	mm_LUT	       	mmLUT[4];     	/* LUT for mm radial displacement */
  coord_3d        *p_c3d;
  target          *p[4];
  target          *c[4];
  target          *n[4];
  target          *t4[4][4];
  int             nt4[4][4];
  corres          *corrp;
  corres	       	*corrc;
  corres	       	*corrn;
  corres	       	*c4[4];
  trackparameters tpar;

 	P *mega[4];

	FILE	*fopen_r ();
	double	multimed_r ();


int  jw_Init();
int  init_proc_c();
int  start_proc_c();
int  pre_processing_c ();
int  detection_proc_c();
int  correspondences_proc_c ();
int  determination_proc_c ();
int  sequence_proc_c();
void checkpoint_proc ();
int  quit_proc_c ();
int  parameter_panel_init();
int  done_proc_c();

void read_ori();
void write_ori ();
void compose_name_plus_nr ();
int  mouse_proc_c ();
void read_image();
int  read_tiff ();
int  write_tiff ();
void copy_images();
void subtract_mask();

int  peak_fit_new();
void highpass();

void zoom ();
void lowpass_n ();
void lowpass_3 ();
void filter_3 ();
void unsharp_mask ();
void split ();
void multimed_nlay ();
void multimed_nlay_v2 ();
void trans_Cam_Point ();
void back_trans_Point ();
void getG();

void quicksort_con ();
int  flow_demo_c();
void simple_connectivity();
void targ_rec();
void quicksort_target_y();
void transp();
void quicksort_coord2d_x();
void rotation_matrix();
void img_xy ();
void img_xy_mm ();
void img_xy_mm_geo ();
 void pixel_to_metric();
void metric_to_pixel ();
 void correct_brown_affin();
void distort_brown_affin ();
int  pix_in_next();
int  kill_in_list ();
void compose_name_plus_nr ();
void compose_name_plus_nr_str ();
int  nearest_neighbour_geo ();
int  nearest_neighbour_pix ();
void bubble_y ();
void init_mmLUT ();


void correspondences_4();
 void det_lsq();
void pos_from_ray();
void dist_to_ray();
 void ray_tracing();
void point_line_line();
 void norm_cross();
 void dot();
 void modu();
 void ray_tracing_v2();
void mid_point();
void cross();
void dotP();
void intersect_rt_3m();
void intersect_rt();
void img_coord_old();
void raw_orient();
void raw_orient_v3();
void raw_orient_v4();
void raw_orient_v5();
int mod();
void getabcFromRot();
void sortgrid_man();
void just_plot();
void det_lsq_3d ();
 void det_lsq_2 ();
 void det_lsq_3 ();
 void det_lsq_4 ();
void orient();
void orient_v3();
void orient_v4();
void prepare_eval();
void eval_ori();
void eval_ori_v2();
void volumedimension();

double epi_line ();
int  epi_mm ();
int  epi_mm_2D ();
void find_candidate_plus_msg ();
void find_candidate_plus ();

int  drawcross();
int  drawvector ();
int  draw_pnr ();
int  draw_value ();
void mark_detections ();
void mark_correspondences ();
void mark_corr ();

 void ata ();
 void ata_v2 ();
 void matinv ();
 void atl ();
 void matmul ();
 void mat_transpose ();

void tracking_proc ();
int  find_track ();

int  candsearch_in_pix ();
int  candsearch_in_pixrest ();
int  corrtest();
void predict();
void readseqtrackcrit ();
void searchquader();
void angle_acc();
void sortwhatfound();
void bubble_foundpix1 ();
void bubble_foundpix2 ();
void tclimg2cimg();

void Pix_crd ();
void Back_trafo ();
void crd_pix();
int  vrmltracks_c();
int  trajectories_c();
int  vrmldetections_c();
int  vrmldettracks_c();


int  tracking();
void read_parameter();
void level1();
void level2();
void level3();
void read_ascii_data();
void rotate_dataset();
void write_ascii_data();
void readcoord_parameter();
void change_coordinates();
void sort();
void neighbours();
int  seq_track_proc_c();

void read_ascii_datanew();
void write_ascii_datanew();
void read_targets();


//double multimed_r_nlay ()