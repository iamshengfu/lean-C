$amsgid = Get-Content -Path "C:\Users\xu.shengfu\Thermo Fisher Scientific\Array and Instrument QA - General\SeqStudio\PowerShell_monitor\messageID.txt"
$msgid = $amsgid.ToString()
$tmpid = $msgid
Write-Host "Monitoring: message ID"
While ($true) {
  $amsgid = Get-Content -Path "C:\Users\xu.shengfu\Thermo Fisher Scientific\Array and Instrument QA - General\SeqStudio\PowerShell_monitor\messageID.txt"
  $msgid = $amsgid.ToString()
  if ($tmpid -ne $msgid)
    {
      $tmpid = $msgid
      $a = Get-Date
      Write-Host "A change has been detected on: " $a
      cmd.exe /c 'C:\Users\xu.shengfu\Thermo Fisher Scientific\Array and Instrument QA - General\SeqStudio\Tracker_file\openvbs.bat'
      Write-Host "Sending Http Post request:"
      $MessageID = Get-Content -Path "C:\Users\xu.shengfu\Thermo Fisher Scientific\Array and Instrument QA - General\SeqStudio\PowerShell_monitor\messageID.txt"
      $body = @{
      "msgid"=$MessageID.ToString()
      }| ConvertTo-Json
      $uriFlow = "https://prod-98.westus.logic.azure.com:443/workflows/edf0d9dd9a1b4175a61a2c6833ccea44/triggers/manual/paths/invoke?api-version=2016-06-01&sp=%2Ftriggers%2Fmanual%2Frun&sv=1.0&sig=ToetMtCjcknG2liE1PASF_hWmXuwm29qDAuFwVHbClI"
      Invoke-RestMethod -Method Post -Uri $uriFlow -Body $body -ContentType "application/json"
      Write-Host "Monitoring: message ID"
      Start-Sleep -Seconds 5
    }
   Start-Sleep -Seconds 5
}