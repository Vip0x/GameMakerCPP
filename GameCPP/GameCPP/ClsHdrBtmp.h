const float WdthPsrj = 31.8;
const float HgthPsrj = 47.9;
const enum { KyUpCnst, KyDnwCnst, KyLftCnst, KyRgtCnst };
#define CnstWtdh 720
#define CnstHgth 550
class ClsObjtBtmp {
protected:
	ALLEGRO_BITMAP *PrsnjPrncplI = NULL;
	ALLEGRO_BITMAP *VrblMpUn = NULL;
	void FcntnCrtdObjtPrsj();
	void Fnctncnmntrbckbffr(ALLEGRO_DISPLAY *PntllLnz);
	void FcntnCgrBtmpBffr();
	bool VrblRcrgrlnz = false;
	int BffrPrsjMvnt_x = ((CnstWtdh / 2) - 15);
	int BffrPrsjMvnt_y = ((CnstHgth / 2) + 20);
	int PsrnjAnmcn_x = 0;
	int PsrnjAnmcn_y = 0;
	int CntrlWtdhMvnt = 0;
	int CntrlHgthMvnt = 0;
};
void ClsObjtBtmp::FcntnCrtdObjtPrsj() {
	al_init_image_addon();
	PrsnjPrncplI = al_load_bitmap("images/ME.png");
	VrblMpUn = al_load_bitmap("images/map2.png");
	al_convert_mask_to_alpha(this->PrsnjPrncplI, al_map_rgb(43, 133, 133));
	if (!PrsnjPrncplI) { exit(-1); }
}
void ClsObjtBtmp::Fnctncnmntrbckbffr(ALLEGRO_DISPLAY *PntllLnz) {
	/* funciona cuando el objeto no es una imagen sino una figura */
	al_set_target_bitmap(al_get_backbuffer(PntllLnz));
}
void ClsObjtBtmp::FcntnCgrBtmpBffr() {
	al_draw_bitmap(this->VrblMpUn, 0, 0, 0);
	al_draw_bitmap_region(this->PrsnjPrncplI, CntrlWtdhMvnt*WdthPsrj, CntrlHgthMvnt*HgthPsrj,
		WdthPsrj, HgthPsrj, BffrPrsjMvnt_x, BffrPrsjMvnt_y, 0);
}
