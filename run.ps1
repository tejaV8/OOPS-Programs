param([string]$name)

$src = Get-ChildItem -Recurse -Filter "$name.cpp" | Select-Object -First 1

if (!$src) {
    Write-Host "Error: $name.cpp not found!"
    exit
}

$binFolder = ".bin"

if (!(Test-Path $binFolder)) {
    New-Item -ItemType Directory -Path $binFolder | Out-Null
}

$output = "$binFolder\$name.exe"

g++ $src.FullName -o $output

if ($?) {
    Write-Host "Compiled Successfully!"
    & $output
}
else {
    Write-Host "Compilation Failed!"
}