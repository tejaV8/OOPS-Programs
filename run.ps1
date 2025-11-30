param([string]$name)

if (-not $name) {
    Write-Host "Usage: run <filename-without-.cpp>"
    exit
}

$src = Get-ChildItem -Recurse -Filter "$name.cpp" | Select-Object -First 1

if (-not $src) {
    Write-Host "❌ '$name.cpp' not found"
    exit
}

$exe = "bin\$name.exe"

g++ $src.FullName -o $exe


if ($LASTEXITCODE -eq 0) {
    & $exe
} else {
    Write-Host "❌ Compilation failed"
}