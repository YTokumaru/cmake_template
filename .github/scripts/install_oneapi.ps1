# This script installs Intel OneAPI components on a GitHub Actions runner.
# It takes the URLs of the basekit and hpckit installers, and the path to a JSON file as parameters.
# The JSON file specifies which components to install.
# The script downloads the installers, and then installs the specified components.

param(
    [string]$basekitUrl,
    [string]$hpckitUrl,
    [string]$jsonFilePath
)

$json = Get-Content -Path $jsonFilePath | ConvertFrom-Json
$basekitComponents = $json.Windows.basekit.components
$hpckitComponents = $json.Windows.hpckit.components

if ($basekitComponents.Count -gt 0) {
    curl.exe -o $env:TEMP\basekit.exe --url $basekitUrl
    foreach ($component in $basekitComponents) {
        Start-Process -FilePath "$env:TEMP\basekit.exe" -ArgumentList "-s -a --silent --eula accept --components $component" -NoNewWindow -Wait
    }
}

if ($hpckitComponents.Count -gt 0) {
    curl.exe -o $env:TEMP\hpckit.exe --url $hpckitUrl
    foreach ($component in $hpckitComponents) {
        Start-Process -FilePath "$env:TEMP\hpckit.exe" -ArgumentList "-s -a --silent --eula accept --components $component" -NoNewWindow -Wait
    }
}