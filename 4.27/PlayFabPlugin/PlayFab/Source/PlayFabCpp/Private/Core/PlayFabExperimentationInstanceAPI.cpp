//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabExperimentationInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::ExperimentationModels;

UPlayFabExperimentationInstanceAPI::UPlayFabExperimentationInstanceAPI()
{
}

UPlayFabExperimentationInstanceAPI::UPlayFabExperimentationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabExperimentationInstanceAPI::UPlayFabExperimentationInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabExperimentationInstanceAPI::UPlayFabExperimentationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabExperimentationInstanceAPI::~UPlayFabExperimentationInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabExperimentationInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabExperimentationInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabExperimentationInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabExperimentationInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabExperimentationInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabExperimentationInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabExperimentationInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabExperimentationInstanceAPI::CreateExclusionGroup(
    ExperimentationModels::FCreateExclusionGroupRequest& request,
    const FCreateExclusionGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/CreateExclusionGroup"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnCreateExclusionGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnCreateExclusionGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateExclusionGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FCreateExclusionGroupResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::CreateExperiment(
    ExperimentationModels::FCreateExperimentRequest& request,
    const FCreateExperimentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/CreateExperiment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnCreateExperimentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnCreateExperimentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateExperimentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FCreateExperimentResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::DeleteExclusionGroup(
    ExperimentationModels::FDeleteExclusionGroupRequest& request,
    const FDeleteExclusionGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/DeleteExclusionGroup"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnDeleteExclusionGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnDeleteExclusionGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteExclusionGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::DeleteExperiment(
    ExperimentationModels::FDeleteExperimentRequest& request,
    const FDeleteExperimentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/DeleteExperiment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnDeleteExperimentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnDeleteExperimentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteExperimentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::GetExclusionGroups(
    ExperimentationModels::FGetExclusionGroupsRequest& request,
    const FGetExclusionGroupsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/GetExclusionGroups"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnGetExclusionGroupsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnGetExclusionGroupsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetExclusionGroupsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FGetExclusionGroupsResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::GetExclusionGroupTraffic(
    ExperimentationModels::FGetExclusionGroupTrafficRequest& request,
    const FGetExclusionGroupTrafficDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/GetExclusionGroupTraffic"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnGetExclusionGroupTrafficResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnGetExclusionGroupTrafficResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetExclusionGroupTrafficDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FGetExclusionGroupTrafficResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::GetExperiments(
    ExperimentationModels::FGetExperimentsRequest& request,
    const FGetExperimentsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/GetExperiments"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnGetExperimentsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnGetExperimentsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetExperimentsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FGetExperimentsResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::GetLatestScorecard(
    ExperimentationModels::FGetLatestScorecardRequest& request,
    const FGetLatestScorecardDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/GetLatestScorecard"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnGetLatestScorecardResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnGetLatestScorecardResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLatestScorecardDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FGetLatestScorecardResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::GetTreatmentAssignment(
    ExperimentationModels::FGetTreatmentAssignmentRequest& request,
    const FGetTreatmentAssignmentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/GetTreatmentAssignment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnGetTreatmentAssignmentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnGetTreatmentAssignmentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTreatmentAssignmentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FGetTreatmentAssignmentResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::StartExperiment(
    ExperimentationModels::FStartExperimentRequest& request,
    const FStartExperimentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/StartExperiment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnStartExperimentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnStartExperimentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FStartExperimentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::StopExperiment(
    ExperimentationModels::FStopExperimentRequest& request,
    const FStopExperimentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/StopExperiment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnStopExperimentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnStopExperimentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FStopExperimentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::UpdateExclusionGroup(
    ExperimentationModels::FUpdateExclusionGroupRequest& request,
    const FUpdateExclusionGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/UpdateExclusionGroup"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnUpdateExclusionGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnUpdateExclusionGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateExclusionGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabExperimentationInstanceAPI::UpdateExperiment(
    ExperimentationModels::FUpdateExperimentRequest& request,
    const FUpdateExperimentDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Experimentation/UpdateExperiment"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabExperimentationInstanceAPI::OnUpdateExperimentResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabExperimentationInstanceAPI::OnUpdateExperimentResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateExperimentDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ExperimentationModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}