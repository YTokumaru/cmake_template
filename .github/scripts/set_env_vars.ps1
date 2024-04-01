# This script sets environment variables for a GitHub Actions runner.
# It takes the path to a batch file as a parameter, calls the batch file to set the environment variables,
# and then writes the new environment variables to the GITHUB_ENV file so they can be used in subsequent steps.

param(
    [string]$batchFilePath
)

Write-Host "Setting environment variables from $batchFilePath"

$before = cmd /c set
$after = cmd /c "call `"$batchFilePath`" >null & set"
$diff = Compare-Object -ReferenceObject $before -DifferenceObject $after
$newVars = $diff | Where-Object { $_.SideIndicator -eq "=>" } | ForEach-Object { $_.InputObject }
foreach ($var in $newVars) {
    $varName, $varValue = $var -split "=", 2
    Write-Output "$varName=$varValue" >> $env:GITHUB_ENV
}