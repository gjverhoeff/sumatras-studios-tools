// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckShadersCompleted_Sumatras.h"
#include "ShaderCompiler.h"

bool UCheckShadersCompletedSumatras::CheckShadersCompleted_Sumatras()
{
	return GShaderCompilingManager->IsCompiling();
}
