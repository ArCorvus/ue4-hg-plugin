//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------
#pragma once

namespace MercurialSourceControl {

/** Slate widget that displays settings for the Mercurial source control provider. */
class SProviderSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SProviderSettingsWidget) {}

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	FText GetMercurialPathText() const;
	void MercurialPath_OnTextCommitted(const FText& InText, ETextCommit::Type InCommitType);
	FReply MercurialPathBrowse_OnClicked();
	EVisibility GetLargeAssetTypeTreeVisibility() const;
	ECheckBoxState EnableLargefilesIntegration_IsChecked() const;
	void EnableLargefilesIntegration_OnCheckStateChanged(ECheckBoxState NewState);
	void LargeAssetTypeTree_OnItemCheckStateChanged();

private:
	FText MercurialPathText;
	bool bEnableLargefilesIntegration;
	TSharedPtr<SBox> LargefilesSettingsBox;
	TSharedPtr<class SLargeAssetTypeTreeWidget> LargeAssetTypeTreeWidget;
};

} // namespace MercurialSourceControl
