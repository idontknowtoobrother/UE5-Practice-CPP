
#include "CoreMinimal.h"
#include "Items/Data/ItemDataStructs.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS()
class ISOPRACTICE_API UItemBase : public UObject
{
	GENERATED_BODY()
	
public:
	/// ======================================================================================================================================================================
	///		VARIABLES & PROPERTIES 
	/// ======================================================================================================================================================================
	UPROPERTY(VisibleAnywhere, Category = "Item Data", meta = (UIMin=1, UIMax=999))
	int32 Quantity;

	UPROPERTY(EditAnywhere, Category= "Item Data")
	FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType Type;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemTextData TextData;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemNumericData NumericData;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemAssetData AssetData;

	/// ======================================================================================================================================================================
	///		FUNCTIONS
	/// ======================================================================================================================================================================
	
	UItemBase();

	UItemBase* CreateItemCopy() const;
	
	UFUNCTION(Category = "Item")
	FORCEINLINE bool CanStackable() const { return NumericData.I32IsStackable && Quantity < NumericData.I32MaxStackSize; }

	UFUNCTION(Category = "Item")
	void SetQuantity(int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(class AWizardCharacter* Character);


protected:
	bool operator==(const FName& OtherID) const {
		return ID == OtherID;
	}
};
