$value = $GET['number'];

echo '<p>';
for($i = 0; $i <= $value; $i++)
{
    echo $i;
    echo ': [';
    for($j = 0; $j <= $value; $j++)
    {
        echo $i * $j;
    }
    echo ']<br>';
}

echo '</p>'