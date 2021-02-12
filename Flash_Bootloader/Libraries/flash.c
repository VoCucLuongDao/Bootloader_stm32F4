#include "flash.h"


/* Private variables ---------------------------------------------------------*/
uint32_t StartSector = 0, EndSector = 0, Address = 0, i=0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0 ;
uint32_t data[520] = { 0x20002010, 0x8004689, 0x80046a5, 0x80046a9, 0x80046ad, 0x80046b1, 0x80046b5, 0x0, 0x0, 0x0, 0x0, 0x80046b9, 0x80046bd, 0x0, 0x80046c1, 0x80046c5, 0x80046c9, 0x80046cd, 0x80046d1, 0x80046d5, 0x80046d9, 0x80046dd, 0x80046e1, 0x80046e5, 0x80046e9, 0x80046ed, 0x80046f1, 0x80046f5, 0x80046f9, 0x80046fd, 0x8004701, 0x8004705, 0x8004709, 0x800470d, 0x8004711, 0x8004715, 0x8004719, 0x800471d, 0x8004721, 0x8004725, 0x8004729, 0x800472d, 0x8004731, 0x8004735, 0x8004739, 0x800473d, 0x8004741, 0x8004745, 0x8004749, 0x800474d, 0x8004751, 0x8004755, 0x8004759, 0x800475d, 0x8004761, 0x8004765, 0x8004769, 0x800476d, 0x8004771, 0x8004775, 0x8004779, 0x800477d, 0x8004781, 0x8004785, 0x8004789, 0x800478d, 0x8004791, 0x8004795, 0x8004799, 0x800479d, 0x80047a1, 0x80047a5, 0x80047a9, 0x80047ad, 0x80047b1, 0x80047b5, 0x80047b9, 0x80047bd, 0x80047c1, 0x80047c5, 0x80047c9, 0x80047cd, 0x80047d1, 0x80047d5, 0x80047d9, 0x80047dd, 0x80047e1, 0x80047e5, 0x80047e9, 0x80047ed, 0x80047f1, 0x80047f5, 0x80047f9, 0x80047fd, 0x8004801, 0x8004805, 0x8004809, 0x800480d, 0x483cb580, 0xf4516801, 0x60010170, 0x6808493a, 0x1f050, 0x20006008, 0x60104a38, 0x4838680a, 0x600a4002, 0x4a384837, 0x68086010, 0x2080f430, 0x20006008, 0x60084935, 0xf805f000, 0x6000f05f, 0x60084933, 0xb082bd01, 0x90012000, 0x90002000, 0x68084929, 0x3080f450, 0x68086008, 0x3000f410, 0x98019000, 0x90011c40, 0x28009800, 0x9801d103, 0x6fa0f5b0, 0x6808d1f1, 0xd5020380, 0x90002001, 0x2000e001, 0x98009000, 0xd12f2801, 0x68024821, 0x5280f052, 0x48206002, 0xf4526802, 0x60024280, 0x68024816, 0x68026002, 0x4200f452, 0x68026002, 0x52a0f452, 0x4a196002, 0x601a4b13, 0xf052680a, 0x600a7280, 0x192680a, 0xf240d5fc, 0x4a146105, 0x68016011, 0x890889, 0x68016001, 0x102f051, 0x68016001, 0x10cf011, 0xd1fa2908, 0x4770b002, 0x0, 0xe000ed88, 0x40023800, 0x40023808, 0xfef6ffff, 0x24003010, 0x40023804, 0x4002380c, 0xe000ed08, 0x40023840, 0x40007000, 0x4405408, 0x40023c00, 0xb088b538, 0xd0004, 0xd13b2d00, 0xd1392c00, 0x483ce072, 0xf0316801, 0x60010104, 0xf44f9805, 0xfbb051fa, 0xf44ff1f1, 0x434170fa, 0x60014836, 0xa804e015, 0xf86cf000, 0x49319805, 0xd2e84288, 0x68014830, 0x104f051, 0x98056001, 0x717af44f, 0xf1f1fbb0, 0x70faf44f, 0x482b4341, 0x20006001, 0x6008492a, 0x68014827, 0x101f051, 0x68016001, 0xd5fc03c9, 0x8496801, 0x60010049, 0x74faf5b4, 0x500f175, 0x10f5f240, 0x428d2100, 0xd801d303, 0xd3004284, 0x4668e7cd, 0xf83af000, 0x49189801, 0xd20d4288, 0x68014817, 0x104f051, 0x98016001, 0x717af44f, 0xf0f1fbb0, 0x49134360, 0xe00c6008, 0x68014810, 0x104f031, 0x98016001, 0x51faf44f, 0xf0f1fbb0, 0x490c4360, 0x20006008, 0x6008490b, 0x68014808, 0x101f051, 0x68016001, 0xd5fc03c9, 0x8496801, 0x60010049, 0xbd30b009, 0x0, 0x7a1200, 0xe000e010, 0xe000e014, 0xe000e018, 0x2100b410, 0x21002100, 0x21002102, 0xf8df2102, 0x681120c4, 0x10cf011, 0xd0042900, 0xd0062904, 0xd0082908, 0xf8dfe02b, 0x600110b4, 0xf8dfe029, 0x600110b0, 0xf8dfe025, 0x682140a0, 0x5180f3c1, 0xf0136823, 0x2900033f, 0xf8dfd008, 0xfbb11094, 0x6821f3f3, 0x1188f3c1, 0xe007434b, 0x107cf8df, 0xf3f3fbb1, 0xf3c16821, 0x434b1188, 0xf3c16821, 0x1c494101, 0xfbb30049, 0x6001f1f1, 0x4917e001, 0x68116001, 0x1f0f011, 0x4b160909, 0x68045c59, 0x604440cc, 0xf4116811, 0xa8951e0, 0x68445c59, 0x608440cc, 0xf4116811, 0xb494160, 0x68425c59, 0x60c240ca, 0x4770bc10, 0x2900b2c9, 0x490ad004, 0x4310680a, 0xe0046008, 0x680a4907, 0xea32, 0x47706008, 0x40023808, 0x40023804, 0xf42400, 0x7a1200, 0x20000000, 0x40023830, 0x2200b4f0, 0x22002200, 0xe0492300, 0xfa142401, 0x680df203, 0x42954015, 0x2503d141, 0x1e6802, 0x76b2f6, 0xf606fa15, 0x600243b2, 0x790f6806, 0xb2d2001a, 0x40970052, 0x6006433e, 0x2a01790a, 0x790ad002, 0xd11a2a02, 0x1e6882, 0x76b2f6, 0xf606fa15, 0x608243b2, 0x794f6886, 0xb2d2001a, 0x40970052, 0x6086433e, 0x409c6842, 0x404ea32, 0x68426044, 0x409c798c, 0x4322b2a4, 0x68c46042, 0xb2d2001a, 0x40950052, 0x505ea34, 0x68c460c5, 0x1a79cd, 0x52b2d2, 0x432c4095, 0x1c5b60c4, 0xd3b32b10, 0x4770bcf0, 0xb2896942, 0x61414051, 0xb4304770, 0x6802e00e, 0x44026843, 0x7dc3008, 0xf1a9bf44, 0x18e30401, 0x5b04f852, 0x5b04f843, 0xd1f91f09, 0x1b04f850, 0xd1ec2900, 0x4770bc30, 0x2101b5e0, 0xf7ff2001, 0x2001ff71, 0x20019000, 0x4f88d, 0xf88d2000, 0x20000005, 0x6f88d, 0x480a4669, 0xff7cf7ff, 0xb580bd07, 0x49094808, 0xb6626008, 0xffe4f7ff, 0x48042101, 0xffc4f7ff, 0x21002064, 0xfe6ef7ff, 0xe7f6, 0x40020000, 0x8008000, 0xe000ed08, 0x4907b510, 0x31184479, 0x447c4c06, 0xe0043416, 0x1d08680a, 0x47884411, 0x42a14601, 0xbd10d1f8, 0x2c, 0x3c, 0x5188f64e, 0x100f2ce, 0xf4406808, 0x60080070, 0x8f4ff3bf, 0x8f6ff3bf, 0x7000f04f, 0xa10eee1, 0x4770, 0xffffff2f, 0x10, 0x1dc, 0x20000000, 0x0, 0xf80df000, 0xd0012800, 0xffcaf7ff, 0x8000f3af, 0xf3af2000, 0xf7ff8000, 0xf000ffac, 0x2001f802, 0xf0004770, 0xb801, 0x46384607, 0xf802f000, 0xe7fb, 0xf3afb580, 0x4a028000, 0x20180011, 0xe7fbbeab, 0x20026, 0x47804801, 0x47004801, 0x8004189, 0x8004699, 0x8000f3af, 0xffb4f7ff, 0xffcef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0xbffef7ff, 0x0, 0x4030201, 0x4030201, 0x9080706 }; 
void Flash_write()
{
     FLASH->KEYR = FLASH_KEY1;
     FLASH->KEYR = FLASH_KEY2;
     FLASH->SR = (FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
     /* Lay number cua Sector bat dau va Sector ket thuc */
     StartSector = GetSector(FLASH_USER_START_ADDR);
     EndSector = GetSector(FLASH_USER_END_ADDR);

     
     for (i = StartSector; i < EndSector; i += 8)
     {
         /* Hieu dien the nam trong khoang [2.7V den 3.6V] */
         FLASH_EraseSector(i, VoltageRange_3) ;
     }
     /* Ghi tung word vao vung nho Flash danh cho nguoi dung
     (vung nho nam giua FLASH_USER_START_ADDR va FLASH_USER_END_ADDR) */
     Address = FLASH_USER_START_ADDR;
     for(int k = 0; k<520; k++)
     {
         FLASH_ProgramWord(Address, data[k]);
         Address = Address + 4;
     }
     /* Lock bo nho Flash de cam truy cap vao thanh ghi dieu khien Flash
     (nham bao ve Flash truoc nhung tac dong khong mong muon) */
     FLASH->CR |= FLASH_CR_LOCK;
}



uint32_t Flash_read(uint32_t address){
    return (*(__IO uint32_t*) address);
}


uint32_t GetSector(uint32_t Address)
{
 uint32_t sector = 0;
 if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
 {
 sector = FLASH_Sector_0;
 }
 else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
 {
 sector = FLASH_Sector_1;
 }
 else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
 {
 sector = FLASH_Sector_2;
 }
 else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
 {
 sector = FLASH_Sector_3;
 }
 else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
 {
 sector = FLASH_Sector_4;
 }
 else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
 {
 sector = FLASH_Sector_5;
 }
 else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
 {
 sector = FLASH_Sector_6;
 }
 else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
 {
 sector = FLASH_Sector_7;
 }
 else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
 {
 sector = FLASH_Sector_8;
 }
 else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
 {
 sector = FLASH_Sector_9;
 }
 else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
 {
 sector = FLASH_Sector_10;
 }
 else
 {
 sector = FLASH_Sector_11;
 }
 return sector;
}
