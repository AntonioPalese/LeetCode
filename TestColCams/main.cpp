#include <vector>
#include <map>

enum class CamEnum
{
    COL_01  = 0x01,
    MONO_01 = 0x02,
    MONO_02 = 0x04,
};

enum class PreProcMode 
{
    STD_PREPROC = 0x08, // numero canali == numero medie/std && numero medie/std != 5
    OLD_PREPROC = 0x10, // numero canali != numero medie/std && numero medie/std == 3
    NEW_PREPROC = 0x20, // numero medie/std == 5
};


std::map<CamEnum, std::map<std::string, std::vector<int>>> test(int cameras, int vecMode, CamEnum actualCam, std::vector<int>& means, std::vector<int>& stds)
{ 
    int mono_mask = 0xfe;
    std::map<CamEnum, std::map<std::string, std::vector<int>>> res;
    switch (cameras | vecMode)
    {
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::STD_PREPROC:
    {        
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[CamEnum::MONO_01].insert({"mean", {means[3]}}); res[CamEnum::MONO_01].insert({"std", {stds[3]}});
        res[CamEnum::MONO_02].insert({"mean", {means[4]}}); res[CamEnum::MONO_02].insert({"std", {stds[4]}});
    } break;
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)PreProcMode::STD_PREPROC:
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::STD_PREPROC:
    {        
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[(CamEnum)(cameras & mono_mask)].insert({"mean", {means[3]}}); res[(CamEnum)(cameras & mono_mask)].insert({"std", {stds[3]}});
    } break;
    case (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::STD_PREPROC:
    {        
        res[CamEnum::MONO_01].insert({"mean", {means[0]}}); res[CamEnum::MONO_01].insert({"std", {stds[0]}});
        res[CamEnum::MONO_02].insert({"mean", {means[1]}}); res[CamEnum::MONO_02].insert({"std", {stds[1]}});
    } break;
    case (int)CamEnum::MONO_01 | (int)PreProcMode::STD_PREPROC:
    case (int)CamEnum::MONO_02 | (int)PreProcMode::STD_PREPROC:
    {        
        res[(CamEnum)(cameras & mono_mask)].insert({"mean", {means[0]}}); res[(CamEnum)(cameras & mono_mask)].insert({"std", {stds[0]}});
    } break;
    case (int)CamEnum::COL_01 | (int)PreProcMode::STD_PREPROC:
    {        
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
    } break;
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::MONO_01 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::MONO_02 | (int)PreProcMode::NEW_PREPROC:
    case (int)CamEnum::COL_01 | (int)PreProcMode::NEW_PREPROC:
    {        
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[CamEnum::MONO_01].insert({"mean", {means[3]}}); res[CamEnum::MONO_01].insert({"std", {stds[3]}});
        res[CamEnum::MONO_02].insert({"mean", {means[4]}}); res[CamEnum::MONO_02].insert({"std", {stds[4]}});
    }break;
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::OLD_PREPROC:
    {        
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[CamEnum::MONO_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::MONO_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[CamEnum::MONO_02].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::MONO_02].insert({"std", {stds[0], stds[1], stds[2]}});
    }break;
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_01 | (int)PreProcMode::OLD_PREPROC:
    case (int)CamEnum::COL_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::OLD_PREPROC:
    {
        res[CamEnum::COL_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::COL_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[(CamEnum)(cameras & mono_mask)].insert({"mean", {means[0], means[1], means[2]}}); res[(CamEnum)(cameras & mono_mask)].insert({"std", {stds[0], stds[1], stds[2]}});
    }break;
    case (int)CamEnum::MONO_01 | (int)CamEnum::MONO_02 | (int)PreProcMode::OLD_PREPROC:
    {
        res[CamEnum::MONO_01].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::MONO_01].insert({"std", {stds[0], stds[1], stds[2]}});
        res[CamEnum::MONO_02].insert({"mean", {means[0], means[1], means[2]}}); res[CamEnum::MONO_02].insert({"std", {stds[0], stds[1], stds[2]}});
    }break;
    case (int)CamEnum::MONO_01 | (int)PreProcMode::OLD_PREPROC:
    case (int)CamEnum::MONO_02 | (int)PreProcMode::OLD_PREPROC:
    case (int)CamEnum::COL_01 | (int)PreProcMode::OLD_PREPROC:
    {
        res[(CamEnum)cameras].insert({"mean", {means[0], means[1], means[2]}}); res[(CamEnum)cameras].insert({"std", {stds[0], stds[1], stds[2]}});
    }break; 
    default:
        break;
    }
    return res;

}
int main()
{


}