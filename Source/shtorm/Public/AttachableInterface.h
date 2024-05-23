 #pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttachableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttachableInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 *
 */
class SHTORM_API IAttachableInterface
{
    GENERATED_BODY()

public:
    // Add interface functions to this class. This is the class that will be inherited to implement this interface.
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Attach")
        void AttachToPlayer(AActor* Player);
};
