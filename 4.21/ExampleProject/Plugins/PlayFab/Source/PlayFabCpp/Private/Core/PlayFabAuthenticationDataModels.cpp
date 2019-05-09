//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabAuthenticationDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

PlayFab::AuthenticationModels::FEntityKey::~FEntityKey()
{

}

void PlayFab::AuthenticationModels::FEntityKey::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("Id")); writer->WriteValue(Id);

    if (Type.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Type")); writer->WriteValue(Type); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FEntityKey::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> IdValue = obj->TryGetField(TEXT("Id"));
    if (IdValue.IsValid() && !IdValue->IsNull())
    {
        FString TmpValue;
        if (IdValue->TryGetString(TmpValue)) { Id = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TypeValue = obj->TryGetField(TEXT("Type"));
    if (TypeValue.IsValid() && !TypeValue->IsNull())
    {
        FString TmpValue;
        if (TypeValue->TryGetString(TmpValue)) { Type = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenRequest::~FGetEntityTokenRequest()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    return HasSucceeded;
}

PlayFab::AuthenticationModels::FGetEntityTokenResponse::~FGetEntityTokenResponse()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::AuthenticationModels::FGetEntityTokenResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    if (EntityToken.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("EntityToken")); writer->WriteValue(EntityToken); }

    if (TokenExpiration.notNull()) { writer->WriteIdentifierPrefix(TEXT("TokenExpiration")); writeDatetime(TokenExpiration, writer); }

    writer->WriteObjectEnd();
}

bool PlayFab::AuthenticationModels::FGetEntityTokenResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> EntityTokenValue = obj->TryGetField(TEXT("EntityToken"));
    if (EntityTokenValue.IsValid() && !EntityTokenValue->IsNull())
    {
        FString TmpValue;
        if (EntityTokenValue->TryGetString(TmpValue)) { EntityToken = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TokenExpirationValue = obj->TryGetField(TEXT("TokenExpiration"));
    if (TokenExpirationValue.IsValid())
        TokenExpiration = readDatetime(TokenExpirationValue);


    return HasSucceeded;
}

